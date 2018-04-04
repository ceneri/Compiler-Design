#include "symbol_table.h"
#include <vector>
#include <unordered_map>
#include <bitset>
#include <string>
#include <cstring>

#include "astree.h"
#include "string_set.h"
#include "lyutils.h"

FILE* outFile;
size_t level;
size_t next_block = 1;
int depth = 0;
vector<symbol_table*> symbol_stack;
vector<int> blockNumberStack;
//Consists of 'void, int, string and identifiuers defined with struct'
symbol_table type_names; //Will be used for holding struct symbols.
//Identifiers that may be used immediately following dor (.) 
//field tabel to be created and accesserd from type_name table
//symbol_table field_names;
//Function and variables  (check local vs global)
symbol_table function_names; //used for holding function symbols
symbol_table prototype_names; //used for holding prototype symbols 




void typecheck_all(astree* root);

//!!this once could take output file
void initialize_tables(FILE* sFile, astree* root){
    //printf( "initializing tables\n");
    outFile = sFile;
    level=0;
    //Initialize all three major tables
    //symbol_stack = new vector<symbol_table*>;
    symbol_stack.push_back( new symbol_table );
    blockNumberStack.push_back( 0 );//global
    //type_names = new symbol_table;
    typecheck_all(root);  
}

//Generate a new symbol with basic info
symbol* new_symbol(astree *node){
    //printf( "Generate a new symbol\n");
    symbol* sym = new symbol();
    sym->attributes = node->attributes;
    sym->fields = NULL;
    sym->filenr = node->lloc.filenr;
    sym->linenr = node->lloc.linenr;
    sym->offset = node->lloc.offset;
    sym->block_nr = blockNumberStack.back();
    sym->parameters = NULL;
    node->block_num = blockNumberStack.back();
    return sym;  
}


string printDepth(){  
    string spaces;
    for(int index = 0; index < depth; index++){
        spaces+="    ";
    }    
    return spaces;
}

void print_symbol(symbol *sym, astree* tree){
    fprintf (outFile, "%s%s (%zd.%zd.%zd) {%zd} ",
            printDepth().c_str(), tree->lexinfo->c_str(),
            sym->filenr, sym->linenr, sym->offset,
            sym->block_nr);
    if (sym->attributes.test(ATTR_struct)){
        fprintf( outFile, "struct \"%s\" ",  
                const_cast<char*>(tree->struct_type->c_str()));
    }
                
    for( int index = 0; index < ATTR_bitset_size; index++){
        if( sym->attributes.test(index)){//check if bit is set
            fprintf( outFile, "%s", getAttrName(index).c_str());
        }
    }
    fprintf( outFile, "\n");
}

//returns pointer to new symbol created, can be ignored
symbol* insert_symbol(symbol_table* table, astree* node){
    //printf( "inserting symbol\n");
    symbol* sym = NULL;   
    //printf( "INSERTING SYMBOL: %s\n", node->lexinfo->c_str());
    if (table != NULL && node != NULL){
        sym = new_symbol(node);
        //print_symbol(sym, node);
        table->insert(symbol_entry(const_cast<string*>(node->lexinfo)
                                    , sym));
    }
    return sym;
}

//Called on a node to set up basic attributes
void set_attributes(astree *node){
    if (node == NULL) return;
    switch (node->symbol){
        case TOK_VOID:
            //printf( "\tTOK_VOID\n");
            node->attributes.set(ATTR_void);
            break;
        case TOK_INT: 
            //printf( "\tTOK_INT\n");
            node->attributes.set(ATTR_int);
            break;
        case TOK_INTCON:
            //printf( "\tTOK_INTCON\n");
            node->attributes.set(ATTR_int);
            node->attributes.set(ATTR_const);
            break;
        case TOK_NULL:
            //printf( "\tTOK_NULL\n");
            node->attributes.set(ATTR_null);
            node->attributes.set(ATTR_const);
            break;
        case TOK_STRING:
            //printf( "\tTOK_STRING\n");
            node->attributes.set(ATTR_string);
            break;
        case TOK_STRINGCON:
            //printf( "\tTOK_STRINGCON\n");
            node->attributes.set(ATTR_string);
            node->attributes.set(ATTR_const);
            break;
        case TOK_STRUCT:
            //printf( "\tTOK_STRUCT\n");
            node->attributes.set(ATTR_struct);
            node->attributes.set(ATTR_typeid);
            break; 
        case TOK_ARRAY:
            //printf( "\tTOK_ARRAY\n");
            node->attributes.set(ATTR_array);
            break;
        case TOK_FUNCTION:
            //printf( "\tTOK_FUNCTION\n");
            node->attributes.set(ATTR_function); 
            break;    
        case TOK_VARDECL:
            //printf( "\tTOK_VARDECL\n");
            //node->attributes.set(ATTR_variable);
            break; 
        case TOK_FIELD:
            //printf( "\tTOK_FIELD\n");
            node->attributes.set(ATTR_field);
            break; 
        case TOK_TYPEID:
            //printf( "\tTOK_TYPEID\n");
            node->attributes.set(ATTR_typeid);
            break; 
        default:
            //printf( "\tNo Attributes\n");
            break;
    }

}
 
/*When entering a block, increment next_block and push nullptr onto
    the top of the symbol stack.*/
void enter_block(){
    //printf( "Entering block\n");
    blockNumberStack.push_back(next_block);
    //printf( "\t\t\t[[%zd]]", next_block);
    next_block++;
    depth++;
    symbol_stack.push_back(NULL);
}

/*When leaving a block, pop the top of the symbol stack.*/
void leave_block(){
    //printf( "Leaving block\n");
    symbol_stack.pop_back();
    blockNumberStack.pop_back();
    depth--;
}

/*When defining an identifier, define a new symbol and insert it
    into the symbol table at the top of the symbol_stack.  Create the
    symbol table if it is null.  Not all blocks have symbols, so do
    not create a symbol table for a given block until it has at least
    one symbol defined in it.
    Only call this func after encountering 
    the first identifier to be defined*/
symbol* define_ident(astree* node){
    //printf( "defining ident\n");

    symbol* sym = new_symbol(node);
    symbol_table* top_table = symbol_stack.back();
    
    if (top_table == NULL){
        symbol_stack.pop_back();
        top_table = new symbol_table();
        symbol_stack.push_back(top_table);
    }

    sym = insert_symbol(top_table, node);
    print_symbol(sym, node);
    
    return sym;
    
}

/*When searching for an identifier, start with the top of the symbol
    stack and check each non-null pointer to a symbol table, searching
    downward.  Local identifiers hide more global ones.*/
symbol* find_ident(astree* node){
    //printf( "finding ident\n");
    bool validTable;
    
    //Go trough every table in the stack
    for (auto table : symbol_stack) {
        
        //Table must not be empty
        validTable = ( table != NULL && !table->empty() );
        
        if (validTable&&
            table->count(const_cast<string*>(node->lexinfo))>0){
            return table->
                find(const_cast<string*>(node->lexinfo))->
                    second;
        }
        
    }
    //Otherwise
    return NULL;
    
}
symbol* find_struct(astree* node){ //checking if already defined
    //printf( "finding ident\n");
    bool validTable;
    symbol_table table = type_names;
    //Go trough every table in the stack
    //Table must not be empty
    validTable = ( !table.empty() );
    
    if (validTable){
        //If said element maps/exits in the current table
        if (table.count(const_cast<string*>(node->lexinfo)) > 0){
            return table.find(const_cast<string*>(node->lexinfo))->
                    second;
        }
        
    }
    //Otherwise
    return NULL;
    
}

bool isStructCompatible(astree* node1, astree* node2){
    //node1 must be same type as ident
    if (node1->attributes.test(ATTR_int) &&
            node2->attributes.test(ATTR_int) ){
                return false;
    }
    else if (node1->attributes.test(ATTR_null) ||
            node2->attributes.test(ATTR_null) ){
                return false;
    }
    else if (node1->attributes.test(ATTR_string) ||
            node2->attributes.test(ATTR_string) ){
                return false;
    }
    else if (node1->attributes.test(ATTR_array) ||
            node2->attributes.test(ATTR_array) ){
                return false;
    }
    //or
    else if (node1->attributes.test(ATTR_string) ||
            node2->attributes.test(ATTR_null) ){
                return false;
    }
    else if (node1->attributes.test(ATTR_array) ||
            node2->attributes.test(ATTR_string) ){
                return false;
    }
    string* structType1 = const_cast<string*>(node1->lexinfo);
    string* node2Lex = const_cast<string*>(node2->lexinfo);
    if( structType1 == node2Lex ){
        return true;
    }else if( node2->children.size()>0){
        //printf( "[[%s]]", structType1->c_str());
        string* node2ChildLex = 
                const_cast<string*>(node2->children[0]->lexinfo);
        //printf( "\t[[%s]]\n", node2ChildLex->c_str());
        if( strcmp(structType1->c_str(), node2ChildLex->c_str())==0){
            //if( structType1 == node2ChildLex ){
                //return true;
            //}
        }
    }
    return false;
}
//Check if two types are compatible
/* Two types are compatible if they are exactly the same type ; 
or if one type is any reference type and the other is null. 
In the type checking grammar, in each rule, types in italics 
must be substituted consistently by compatible types. Types 
are compatible only if the array attribute is on for both 
or off for both.
*/
bool check_compatible(astree* node1, astree* node2){
    //printf( "checking compatibility\n");
    if (node1->attributes.test(ATTR_int) &&
            node2->attributes.test(ATTR_int) ){
                return true;
    }
    else if (node1->attributes.test(ATTR_null) &&
            node2->attributes.test(ATTR_null) ){
                return true;
    }
    else if (node1->attributes.test(ATTR_string) &&
            node2->attributes.test(ATTR_string) ){
                return true;
    }
    else if (node1->attributes.test(ATTR_array) &&
            node2->attributes.test(ATTR_array) ){
                return true;
    }
    //or
    else if (node1->attributes.test(ATTR_string) &&
            node2->attributes.test(ATTR_null) ){
                return true;
    }
    else if (node1->attributes.test(ATTR_array) &&
            node2->attributes.test(ATTR_string) ){
                return true;
    }
    else if( isStructCompatible(node1, node2)){
        return true;
    }
        return false;
}

//Function adds symbol to type_names table, and created a 
//table for struct fields 
void inherit_attributes( int parentSymbol, astree* node ){
    if (node == NULL) return;
    switch (parentSymbol){
        case TOK_VOID:
            //printf( "\tTOK_VOID\n");
            node->attributes.set(ATTR_void);
            break;
        case TOK_INT: 
            //printf( "\tTOK_INT\n");
            node->attributes.set(ATTR_int);
            break;
        case TOK_INTCON:
            //printf( "\tTOK_INTCON\n");
            node->attributes.set(ATTR_int);
            node->attributes.set(ATTR_const);
            break;
        case TOK_NULL:
            //printf( "\tTOK_NULL\n");
            node->attributes.set(ATTR_null);
            node->attributes.set(ATTR_const);
            break;
        case TOK_STRING:
            //printf( "\tTOK_STRING\n");
            node->attributes.set(ATTR_string);
            break;
        case TOK_STRINGCON:
            //printf( "\tTOK_STRINGCON\n");
            node->attributes.set(ATTR_string);
            node->attributes.set(ATTR_const);
            break;
        case TOK_STRUCT:
            //printf( "\tTOK_STRUCT\n");
            node->attributes.set(ATTR_struct);
            node->attributes.set(ATTR_typeid);
            break; 
        case TOK_ARRAY:
            //printf( "\tTOK_ARRAY\n");
            node->attributes.set(ATTR_array);
            break;
        case TOK_FUNCTION:
            //printf( "\tTOK_FUNCTION\n");
            node->attributes.set(ATTR_function); 
            break;    
        case TOK_VARDECL:
            //printf( "\tTOK_VARDECL\n");
            //node->attributes.set(ATTR_variable);
            break; 
        case TOK_FIELD:
            //printf( "\tTOK_FIELD\n");
            node->attributes.set(ATTR_field);
            break; 
        case TOK_TYPEID:
            //printf( "\tTOK_TYPEID\n");
            node->attributes.set(ATTR_typeid);
            break; 
        default:
            //printf( "\tNo Attributes\n");
            break;
    }    
}

void new_struct(astree* node){
    //node must not be null and children list must not be empty
    if( node != NULL && !node->children.empty()){
        //check if the struct has a name
        if ( node->children[0] != NULL ){ 
            symbol* struct_sym = find_struct( node->children[0] );
            if( struct_sym == NULL ){ //create from scratch
                //create/insert if it didn't exist
                struct_sym = 
                        insert_symbol(&type_names, node->children[0]);
                print_symbol(struct_sym, node->children[0]);
                if( node->children.size()>1){
                    symbol_table *field_table = new symbol_table();
                    depth++;
                    for( auto &child : node->children[1]->children ) {
                        inherit_attributes(
                            child->symbol, child->children[0] );
                        symbol *new_sym = 
                            insert_symbol( 
                                field_table, child->children[0]);
                        print_symbol(new_sym, child->children[0]);
                    }
                    depth--;
                    fprintf (outFile, "\n");
                    
                    struct_sym->fields = field_table;
                }else{
                    struct_sym->fields = NULL;
                }
            }else{ //probably specifying fields
                if( struct_sym->fields == NULL){
                    if( node->children.size()>1){ 
                        symbol_table *field_table = new symbol_table();
                        for( auto &child : 
                            node->children[1]->children ) {
                            //printf("\t");
                            inherit_attributes(child->symbol, 
                                child->children[0] );
                            insert_symbol( field_table, 
                                child->children[0]);
                        }
                        struct_sym->fields = field_table;
                    }
                    
                }else{
                    //either a duplication error or we can ignore
                    if( node->children.size()>1){
                        fprintf (stderr, "ERROR: ALREADY ");
                        fprintf (stderr, "HAVE DEFINED FIELDS\n");
                    }
                }
            }            
        }
    }
    
    return;
}

symbol* find_prototype(astree* node){ //checking if already defined
    bool validTable;
    
    //Prototype Table must not be empty
    validTable = ( !prototype_names.empty() );
    
    if (validTable){
        //If said element maps/exits in the prototype table
        if (prototype_names.count(
            const_cast<string*>(node->lexinfo)) > 0){
                
            return prototype_names.find(
                const_cast<string*>(node->lexinfo))->second;
        }
        
    }
    //Otherwise
    return NULL;   
}

//!!TODO make sure block # is done properly
void new_prototype(astree* node){
    
    if( node != NULL && !node->children.empty()){
        //check if the function has a name
        astree* identdecl = node->children[0];
        if ( identdecl != NULL ){
            astree* func_name = identdecl->children[0];
            //does it already exist?
            symbol* func_sym = find_prototype( func_name );
            if( func_sym == NULL ){ //create/insert if it didn't exist
            
                //create a prototype symbol
                inherit_attributes(identdecl->symbol, func_name );
                func_name->attributes.set(ATTR_function);
                
                //only insert in the prototypes table,not in the stack 
                //right??? but it might still use a block?
                func_sym = insert_symbol(&prototype_names, func_name);
                /*!!we dont put at the top of stack because it cannot 
                be called since it is only prototype*/
                
                //Check if there are any parameters
                if( node->children.size()>1 
                    && node->children[1] != NULL){
                    //Initialize the vector
                    func_sym->parameters = new vector<symbol*>();
                    //handle each paramter
                    for( auto &param : node->children[1]->children ) {
                        //Inherit attribut
                        inherit_attributes(param->symbol,
                            param->children[0] );
                        //Set parameter attributes
                        param->children[0]->attributes.set(
                            ATTR_variable);
                        param->children[0]->attributes.set(ATTR_param);
                        param->children[0]->attributes.set(ATTR_lval);
                        //Insert to table at the top of the stack
                        symbol* param_sym = new_symbol(
                            param->children[0]);
                        //Save to symbol stack of params
                        func_sym->parameters->push_back(param_sym);
                    }
                    
                } else {
                    //If there are no parameters, set it to NULL 
                    func_sym->parameters = NULL;
                }
                
            } else { //Already exists
                fprintf (stderr, "ERROR: PROTOTYPE ");
                fprintf (stderr, "PREVIOUSLY DEFINED\n");
            }
        }
    }

}

symbol* find_function(astree* node){ //checking if already defined
    bool validTable;
    
    //Function Table must not be empty
    validTable = ( !function_names.empty() );
    
    if (validTable){
        //If said element maps/exits in the prototype table
        if (function_names.count(
            const_cast<string*>(node->lexinfo)) > 0){
                
            return function_names.find(
                const_cast<string*>(node->lexinfo))->second;
        }
        
    }
    //Otherwise
    return NULL;   
}

//!!TODO make sure block # is done properly
void new_function(astree* node){
    
    if( node != NULL && !node->children.empty()){
        //check if the function has a name
        astree* identdecl = node->children[0];
        if ( identdecl != NULL && !identdecl->children.empty()){
            //printf("lets see %s\n", identdecl->lexinfo->c_str());
            typecheck_all(identdecl);//set attributes
            astree* func_name = identdecl->children[0];
            //does it already exist?
            symbol* func_sym = find_function( func_name );
             //printf("or here\n");
            if( func_sym == NULL ){ //Does not exist yet
            
                //create function symbol
                inherit_attributes(identdecl->symbol, func_name );
                func_name->attributes.set(ATTR_function);
                //this also add to top of stack table
                func_sym = define_ident(func_name); 
                //printf("Function symbol created\n");
                
                //Manually add symbol to funtion table, cannot use 
                //insert_symbol because it creates a different symbol
                function_names.insert(symbol_entry(
                    const_cast<string*>(func_name->lexinfo), func_sym));
                
                //Check if there are any parameters
                if( node->children.size()>1 && 
                    node->children[1] != NULL){
                    //set attributes to all parameters
                    typecheck_all(node->children[1]);
                    
                    //Initialize the vector
                    func_sym->parameters = new vector<symbol*>();
                    
                    //!!current block number + 1
                    blockNumberStack.push_back(blockNumberStack.back()
                    + 1 );
                    depth++;
                    //handle each paramter
                    //printf("Check Children\n");
                    for( auto &param : node->children[1]->children ) {
                        //Inherit attribut
                        inherit_attributes(param->symbol,
                            param->children[0] );
                        //Set parameter attributes
                        param->children[0]->attributes.set(
                            ATTR_variable);
                        param->children[0]->attributes.set(ATTR_param);
                        param->children[0]->attributes.set(ATTR_lval);
                        //Insert to table at the top of the stack
                        symbol* param_sym = define_ident(
                            param->children[0]);
                        //Save to symbol stack of params
                        func_sym->parameters->push_back(param_sym);
                    }
                    depth--;
                    
                    fprintf (outFile, "\n");  
                    
                    //!!Remove block number + 1
                    //printf("Pop Stack\n");
                    blockNumberStack.pop_back();
                    
                } else {
                    //If there are no parameters, set it to NULL 
                    func_sym->parameters = NULL;
                }
                    
                //does it already exist as prototype?
                symbol* prototype_sym = find_prototype( func_name );
                if( prototype_sym != NULL ){ 
                //Already exists as prototype
                    
                    //Check that parameters match
                    bool match;
                    if ( prototype_sym->parameters->size() < 
                        func_sym->parameters->size() ) {
                        match = std::equal ( 
                            prototype_sym->parameters->begin(), 
                            prototype_sym->parameters->end(),
                            func_sym->parameters->begin() );
                        }
                    else {
                        match = std::equal ( 
                            func_sym->parameters->begin(),
                            func_sym->parameters->begin(), 
                            prototype_sym->parameters->begin() );
                    }
                    
                    if (match){
                        //Pop symbol from prototype table
                        prototype_names.erase(
                            const_cast<string*>(func_name->lexinfo));
                    } else {
                        printf("ERROR: FUNCTION DOES NOT MATCH");
                        printf(" PREVIOUS PROTOTYPE\n");
                        return;
                    }                 
                } 
                
                //!!perform block operation on actual body of function
                enter_block();
                typecheck_all(node->children[2]);
                    
            } else { //Already exists
                printf("ERROR: FUNCTION PREVIOUSLY DEFINED\n");
            }    
        } 
    }
}



//Function adds symbol to type_names table, and created a 
//table for struct fields 
void new_variable(astree* node){
    //printf( "new variable\n");
    astree* identdcl = node->children[0];
    //astree* compatible = node->children[1];

    identdcl->children[0]->attributes.set(ATTR_variable);
    identdcl->children[0]->attributes.set(ATTR_lval);
    
    //if (!check_compatible(identdcl, compatible)){
        /*print error */
        //printf("NOT COMPATIBLE\n");
        //return;
    //}
    //Does not exist yet
    if (find_ident(identdcl) == NULL){
        define_ident(identdcl->children[0]);
    }else{
        /*Print errror, another variable has the same name*/
    }   
}

//Function adds symbol to type_names table, and created a 
//table for struct fields 
void allocate_variable(astree* node){
    //printf( "allocating variable\n");
    astree* left = node->children[0];
    //astree* right = node->children[1];

    node->attributes.set(ATTR_vreg);
    //redundant but it does not hurt
    left->attributes.set(ATTR_variable);
    left->attributes.set(ATTR_lval);
    
    /*2.4(c) The result of an assignment is the type of its 
    left operand*/
    for (size_t att = 0; att < ATTR_function; att++) {
        if (left->attributes.test(att)) {
            node->attributes.set(att);
        }
    } 

}

//handles TOk_INDEX typechecking
void typecheck_index(astree* node){
    //printf( "typechecking index\n");
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




/*Field selection sets the selector (.) attribute as follows : 
The left operand must be a struct type or an error message is 
generated. Look up the field in the structure and copy its type 
attributes to the selector, removing the field attribute and 
adding the vaddr attribute.
void typecheck_selector(astree* node){
    astree* left;
    astree* right;
    
    //printf( "typechecking index\n");
    if( node->children.size() > 0){
        left = node->children[0];
        if( node->children.size() > 1){
            right = node->children[1];
        }
        
        printf( "struct type is: %s\n", 
            const_cast<char*>(left->struct_type->c_str()));
        
        //check that it is a valid struct 
        symbol *sym = find_ident(left);
        if (sym != NULL){
            symbol_table* f_table = sym->fields;
            
            //If said element maps/exits in the current table
            if (f_table->count(const_cast<string*>(right->lexinfo)) 
                        > 0){
                symbol *valid_field = f_table->find(
                    const_cast<string*>(right->lexinfo))->second;
                
                //copy its type attributes to the selector
                for (size_t att = 0; att < ATTR_function; att++) {
                    if (valid_field->attributes.test(att)) {
                        node->attributes.set(att);
                    }
                }
                
                //removing the field attribute and adding the 
                //vaddr attribute
                node->attributes.set(ATTR_vaddr);
                //node->attributes.set(ATTR_lval);
                node->attributes.reset(ATTR_field);
            }
            
        } else{
            //!!Print invalid int index error
        }
    }  

}*/
void typecheck(astree* root);
void recursive_block_handler(astree* node){
    if(node->symbol==TOK_BLOCK&&node->block_num ==0){enter_block();}
    //save block number into ast so it transfers over 
    //when we create those symbol structs
    if( node->block_num ==0){
        node->block_num = blockNumberStack.back();
    }
    for( auto child : node->children ){
        //depth++;
        recursive_block_handler( child );
        if( child->symbol!=TOK_BLOCK){
            typecheck( child );
        }
        //depth--;
    }
}

void block_handler(astree* node){
    //don't check for tok_block b/c we will use this for 
    //other types
    if(node->block_num == 0){
        enter_block();
        node->block_num = blockNumberStack.back();
    }
    for( auto child : node->children ){
        //depth++;
        recursive_block_handler( child );
        if( child->symbol!=TOK_BLOCK){
            typecheck( child );
        }
        //depth--;
    }
}

//Perform single nose typecheck
//!!printing could also be performed here
void typecheck(astree* root){
    //printf( "~typechecking node: %s\n", root->lexinfo->c_str());

    astree* left;
    astree* right;
    int token_code;
    bool valid;

    //!!for now
    symbol *t_sym;

    //printf("~Checking its children\n");
    //!!might not have children
    bool validLeft = root->children.size() > 0;
    bool validRight = root->children.size() > 1;
    token_code = root->symbol;
    if( validLeft){
        left = root->children[0];
        if( validRight){
            right = root->children[1];
        }
    }
    
    //setup basic attributes
    //printf("~about to set attributes\n");
    set_attributes(root);
    //printf("Ste att%s\n", root->lexinfo->c_str());
    //printf( "~about to switch with [%d]\n\t", token_code);
    switch(token_code){
        
        case TOK_BLOCK:
            leave_block();
            break;
        case TOK_IF:
        case TOK_ELSE:
        case TOK_WHILE:
            //done
            //printf( "A\n");
            if(validLeft){
                if( !(left->attributes.test(ATTR_vreg) || 
                                left->attributes.test(ATTR_int))){
                    fprintf( stderr, "ERROR: INVALID ");
                    fprintf( stderr, "IF/ELSE/WHILE STATEMENT\n");
                }
            }
            break;
        case TOK_STRUCT: 
            //printf( "B\n");
            //enter_block();
            new_struct(root);
            t_sym = find_ident(root);
            if (t_sym != NULL){
                root->origin_filenr = t_sym->filenr;
                root->origin_linenr = t_sym->linenr;
                root->origin_offset = t_sym->offset;
            }

            break;
        case TOK_FUNCTION:
                //printf( "FUNC\n");
                new_function(root);
                break;
        case TOK_PROTOTYPE:
                new_prototype(root);
                break;
        case TOK_VARDECL:   
            //printf( "vardecl\n");
            new_variable(root);
            t_sym = find_ident(root->children[0]);
            if (t_sym != NULL){
                
                root->children[0]->children[0]->origin_filenr
                    = t_sym->filenr;
                root->children[0]->children[0]->origin_filenr 
                    = t_sym->linenr;
                root->children[0]->children[0]->origin_filenr 
                    = t_sym->offset;
            }
            break;  
        case TOK_RETURN:
        /*!!*/
        case TOK_RETURNVOID:
         /*!!*/
            //printf( "C\n");
            break;
        case '=':
            allocate_variable(root);
            break;
        /*All inequalities have the same typechecking rules*/  
        case TOK_EQ:
        case TOK_NE:
        case TOK_LT:
        case TOK_LE: 
        case TOK_GT: 
        case TOK_GE:
            //printf( "D\n");
            root->attributes.set(ATTR_vreg);
            root->attributes.set(ATTR_int);
            break;
        /*All basic ops have the same typechecking rules*/
        case '+':   
        case '-':
        case '*':
        case '/':
        case '%':
            //printf( "E\n");
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
            //printf( "F\n");
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
            //printf( "G\n");
            break;
        case TOK_NEWSTRING:
            //printf( "H\n");
            valid = left->attributes.test(ATTR_int); 
                    
            if (valid){
                root->attributes.set(ATTR_vreg);
                root->attributes.set(ATTR_string);
            } else{
                //!!print error
            }
            break;
        case TOK_NEWARRAY:
            //printf( "I\n");
            /*Check that the type id is in thge struct table*/
            break;
        case TOK_TYPEID:
            if ( !root->children.empty() ){
                root->children[0]->attributes.set(ATTR_struct);
                root->children[0]->struct_type = root->lexinfo; 
            } else {
                //printf( "No children, lexinfo %s\n", 
                //const_cast<char*>(root->lexinfo->c_str()));
            }
        case TOK_VOID:
        case TOK_INT:
        case TOK_STRING:
        case TOK_CHAR:
        
            /*Identifiers have the type attributes that they derive 
            from the symbol table. Inaddition, either the function 
            or variable attribute will be present, and for variables
            that are parameters, also the param attribute. All 
            variables also have the lval attribute.*/
            //if (find_ident(root) == NULL){
                /*printerror*/
            //}
            
            if ( !root->children.empty() ){
                inherit_attributes(root->symbol, root->children[0] );
            }
            
                        
            break;
        case TOK_INDEX:
            //printf( "J\n");
            typecheck_index(root);
            break;
        case '.':
            //typecheck_selector(root);
            break;
        default:
            //printf( "ERROR\n");
            break;
    }
    
    
}

//post order depth first search traversal
void typecheck_all(astree* root){
    //depth--;
    //printf( "typechecking all [root=%s]\n\n", root->lexinfo->c_str());
    for (auto child : root->children){
        //printf( "<<<checking child>>>\n");
        //level++;
        //depth++;
        if( child->symbol == TOK_BLOCK){
            //depth++;
            enter_block();
            //block_handler(child);
            //printf("\t\t\t\t\t\t{{{(block)index=%zd}}}\n", level);
        }else if(child->symbol == TOK_PARAMLIST){
            //depth++;
            //enter_block();
        }else if(child->symbol == TOK_FUNCTION){
            //printf( "function   \n");
            //enter_block();
            typecheck(child);
            continue;
        }else if(child->symbol == TOK_PROTOTYPE){
            //printf( "prototype   \n");
            //enter_block();
        }
        typecheck_all(child);
        //depth--;
        //printf( "<<ready for next child>>\n\n");
    }
    //printf( "<<<checking root[level=%zd]>>>\n", level);
    typecheck(root);
    //printf("<<finished root>>\n\n");
}
