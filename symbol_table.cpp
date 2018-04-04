#include "symbol_table.h"
#include <vector>
#include <unordered_map>
#include <bitset>
#include <string>

#include "astree.h"
#include "string_set.h"
#include "lyutils.h"

FILE* outFile;

size_t next_block = 1;
vector<symbol_table*> symbol_stack;

//Consists of 'void, int, string and identifiuers defined with struct'
symbol_table type_names;
//Identifiers that may be used immediately following dor (.) 
//field tabel to be created and accesserd from type_name table
symbol_table field_names;
//Function and variables  (check local vs global)
symbol_table func_var_names;


void typecheck_all(astree* root);

//!!this once could take output file
void initialize_tables(FILE* sFile, astree* root){
    printf( "AAA\n");
    outFile = sFile;
    
    //Initialize all three major tables
    //symbol_stack = new vector<symbol_table*>;
    symbol_stack.push_back( new symbol_table );
    //type_names = new symbol_table;
    typecheck_all(root);  
}

//Generate a new symbol with basic info
symbol* new_symbol(astree *node){
    symbol* sym = new symbol();
    
    sym->attributes = node->attributes;
    sym->fields = NULL;
    sym->filenr = node->lloc.filenr;
    sym->linenr = node->lloc.linenr;
    sym->offset = node->lloc.offset;
    sym->offset = node->block_num;
    sym->parameters = NULL;
    
    return sym;  
}

void print_symbol(symbol *sym, astree* tree){
    fprintf (/*outFile*/stdout, "%s (%zd.%zd.%zd) {%zd} ",
            tree->lexinfo->c_str(),
            sym->filenr, sym->linenr, sym->offset,
            sym->block_nr);
    for( int index = 0; index < ATTR_bitset_size; index++){
        if( sym->attributes.test(index)){//check if bit is set
            fprintf( /*outFile*/stdout, "%s ", getAttrName(index).c_str());
        }
    }
    fprintf( /*outFile*/stdout, "\n ");
}

//returns pointer to new symbol created, can be ignored
symbol* insert_symbol(symbol_table* table, astree* node){
    symbol* sym = NULL;   
    
    if (table != NULL && node != NULL){
        sym = new_symbol(node);
        print_symbol(sym, node);
        table->insert(symbol_entry(const_cast<string*>(node->lexinfo), sym));
    }
    return sym;
}

//Called on a node to set up basic attributes
void set_attributes(astree *node){
    if (node == NULL) return;
    switch (node->symbol){
        case TOK_VOID:
            node->attributes.set(ATTR_void);
            break;
        case TOK_INT: 
            node->attributes.set(ATTR_int);
            break;
        case TOK_INTCON:
            node->attributes.set(ATTR_int);
            node->attributes.set(ATTR_const);
            break;
        case TOK_NULL:
            node->attributes.set(ATTR_null);
            node->attributes.set(ATTR_const);
            break;
        case TOK_STRING:
            node->attributes.set(ATTR_string);
            break;
        case TOK_STRINGCON:
            node->attributes.set(ATTR_string);
            node->attributes.set(ATTR_const);
            break;
        case TOK_STRUCT:
            node->attributes.set(ATTR_struct);
            node->attributes.set(ATTR_typeid);
            break; 
        case TOK_ARRAY:
            node->attributes.set(ATTR_array);
            break;
        case TOK_FUNCTION:
            node->attributes.set(ATTR_function); 
            break;    
        case TOK_VARDECL:
            //node->attributes.set(ATTR_variable);
            break; 
        case TOK_FIELD:
            node->attributes.set(ATTR_field);
            break; 
        case TOK_TYPEID:
            node->attributes.set(ATTR_typeid);
            break; 
        
    }

}
 
/*When entering a block, increment next_block and push nullptr onto
    the top of the symbol stack.*/
void enter_block(){
    next_block++;
    symbol_stack.push_back(nullptr);
}

/*When leaving a block, pop the top of the symbol stack.*/
void leave_block(){
    symbol_stack.pop_back();
}

/*When defining an identifier, define a new symbol and insert it
    into the symbol table at the top of the symbol_stack.  Create the
    symbol table if it is null.  Not all blocks have symbols, so do
    not create a symbol table for a given block until it has at least
    one symbol defined in it.
    Only call this func after encountering the first identifier to be defined*/
void define_ident(astree* node){
    symbol* sym = new_symbol(node);
    symbol_table* top_table = symbol_stack.front();
    
    if (top_table == NULL){
        top_table = new symbol_table();
    }

    top_table->insert( symbol_entry(const_cast<string*>(node->lexinfo), sym) );
    
}

/*When searching for an identifier, start with the top of the symbol
    stack and check each non-null pointer to a symbol table, searching
    downward.  Local identifiers hide more global ones.*/
symbol* find_ident(astree* node){
    bool validTable;
    
    //Go trough every table in the stack
    for (auto table : symbol_stack) {
        
        //Table must not be empty
        validTable = ( table != NULL && !table->empty() );
        
        if (validTable){
            
            //If said element maps/exits in the current table
            if (table->count(const_cast<string*>(node->lexinfo)) > 0){
                return table->find(const_cast<string*>(node->lexinfo))->second;
            }
            
        }
        
    }
    
    //Otherwise
    return NULL;
    
}

//Check if two types are compatible
/* Two types are compatible if they are exactly the same type ; or if one type is
any reference type and the other is null. In the type checking grammar, in each
rule, types in italics must be substituted consistently by compatible types.
Types are compatible only if the array attribute is on for both or off for both.
*/
bool check_compatible(astree* node1, astree* node2){
    
    if (node1->attributes.test(ATTR_int) &&
            node2->attributes.test(ATTR_int) ){
                return true;
    }
    if (node1->attributes.test(ATTR_null) &&
            node2->attributes.test(ATTR_null) ){
                return true;
    }
    if (node1->attributes.test(ATTR_string) &&
            node2->attributes.test(ATTR_string) ){
                return true;
    }
    if (node1->attributes.test(ATTR_array) &&
            node2->attributes.test(ATTR_array) ){
                return true;
    }
    //or
    if (node1->attributes.test(ATTR_string) &&
            node2->attributes.test(ATTR_null) ){
                return true;
    }
    if (node1->attributes.test(ATTR_array) &&
            node2->attributes.test(ATTR_string) ){
                return true;
    }
    
        return false;
}

//Function adds symbol to type_names table, and created a 
//table for struct fields 
void new_struct(astree* node){
    
    //node is not null an children list is not empty
    if( node != NULL && !node->children.empty()){
        //children where valid type name is is not null
        if ( node->children[0] != NULL ){
            symbol* new_sym = insert_symbol(&type_names, node->children[0]);
            
            //create a field table
            symbol_table *field_table = new symbol_table();
            for (auto &child : node->children) {
                //ignore the first child, since we arleady used it to get the name
                if (child == node->children[0]) continue;
                
                //invalid field
                if ( child->children.empty() || child->children[0] == NULL) return;
                
                //set attribute of field and insert into field table
                child->attributes.set(ATTR_field);
                insert_symbol(field_table, child);
            }
            
            //add field table to new symbol
            new_sym->fields = field_table;
            
            //Enter the new field table to the global field table
            //field_names.insert(field_table); //!!!! Check this line 
            //For now leave commented out until we figure out wether
            //fiedl_table should be a stack, or a table
            
            //Save reference to symbol_entry
            //node->struct_t = new symbol_entry((string*)struct_name->lexinfo, new_sym);
            
        }
    }
    
    return;
}



//Function adds symbol to type_names table, and created a 
//table for struct fields 
void new_variable(astree* node){
    astree* identdcl = node->children[0];
    astree* compatible = node->children[1];

    identdcl->attributes.set(ATTR_variable);
    identdcl->attributes.set(ATTR_lval);
    
    if (!check_compatible(identdcl, compatible)){
        /*print error */
        return;
    }
    
    //Does not exist yet
    if (find_ident(identdcl) == NULL){
        define_ident(identdcl);
    } else{
        /*Print errror, another variable has the same name*/
    }   
    
}

//Function adds symbol to type_names table, and created a 
//table for struct fields 
void allocate_variable(astree* node){
    astree* left = node->children[0];
    //astree* right = node->children[1];

    node->attributes.set(ATTR_vreg);
    //redundant but it does not hurt
    left->attributes.set(ATTR_variable);
    left->attributes.set(ATTR_lval);
    
    /*2.4(c) The result of an assignment is the type of its left operand*/
    for (size_t att = 0; att < ATTR_function; att++) {
        if (left->attributes.test(att)) {
            node->attributes.set(att);
        }
    } 

}

//handles TOk_INDEX typechecking
void typecheck_index(astree* node){
    astree* left = node->children[0];
    astree* right = node->children[1];
    
    //Check there is a valid index
    if ( right->attributes.test(ATTR_int) ){
    
        //String indexing
        bool valid = left->attributes.test(ATTR_string);
                    
        if (valid){
            node->attributes.set(ATTR_int);
            node->attributes.set(ATTR_vaddr);
            node->attributes.set(ATTR_lval);
            return;
        } 
    
        //Base indexing
        valid = left->attributes.test(ATTR_int);
        if (valid){
            node->attributes.set(ATTR_int);
            node->attributes.set(ATTR_vaddr);
            node->attributes.set(ATTR_lval);
            return;
        } 

        valid = left->attributes.test(ATTR_typeid);
        if (valid){
            node->attributes.set(ATTR_typeid);
            node->attributes.set(ATTR_vaddr);
            node->attributes.set(ATTR_lval);
            return;
        }
            
        valid = left->attributes.test(ATTR_array);
        if (valid){
            node->attributes.set(ATTR_array);
            node->attributes.set(ATTR_vaddr);
            node->attributes.set(ATTR_lval);
            return;
        }
        
        /*!!if you get to here print invalid array type*/
    
    } else {
        //!!Print invalid int index error
    }

}

//Perform single nose typecheck
//!!printing could also be performed here
void typecheck(astree* root){
    astree* left;
    astree* right;
    int token_code;
    bool valid;
    
    //!!might not have children
    token_code = root->symbol;
    left = root->children[0];
    right = root->children[1];
    
    //setup basic attributes
    set_attributes(root);
    
    switch(token_code){
        
        case TOK_IF:
        case TOK_ELSE:
        case TOK_WHILE:
            enter_block();
            break;
        case TOK_STRUCT: 
            enter_block();
            new_struct(root);
            break;
        case TOK_VARDECL:   
            new_variable(root);
            break;  
        case TOK_RETURN:
        /*!!*/
        case TOK_RETURNVOID:
         /*!!*/
            break;
        case '=':
            allocate_variable(root);
            break;
        case TOK_EQ:     /*All inequalities have the same typechecking rules*/
        case TOK_NE:
        case TOK_LT:
        case TOK_LE: 
        case TOK_GT: 
        case TOK_GE:
            root->attributes.set(ATTR_vreg);
            root->attributes.set(ATTR_int);
            break;
        case '+':       /*All basic ops have the same typechecking rules*/
        case '-':
        case '*':
        case '/':
        case '%':
            valid = left->attributes.test(ATTR_int) &&
                    right->attributes.test(ATTR_int); 
                    
            if (valid){
                root->attributes.set(ATTR_vreg);
                root->attributes.set(ATTR_int);
            } else{
                //!!print error
            }
            break;
        case TOK_POS:       /*Unary operands*/
        case TOK_NEG:
        case '!':
            valid = left->attributes.test(ATTR_int); 
                    
            if (valid){
                root->attributes.set(ATTR_vreg);
                root->attributes.set(ATTR_int);
            } else{
                //!!print error
            }
            break;
        case TOK_NEW:
            /*Check that the type id is in thge struct table*/
            break;
        case TOK_NEWSTRING:
            valid = left->attributes.test(ATTR_int); 
                    
            if (valid){
                root->attributes.set(ATTR_vreg);
                root->attributes.set(ATTR_string);
            } else{
                //!!print error
            }
            break;
        case TOK_NEWARRAY:
            /*Check that the type id is in thge struct table*/
            break;
        case TOK_INDEX:
            typecheck_index(root);
            break;
    }
    
    
}

//post order depth first search traversal
void typecheck_all(astree* root){
    for (auto child : root->children){
        typecheck(child);
    }
    typecheck(root);
}
    