// $Id: astree.cpp,v 1.15 2017-10-05 16:39:39-07 - - $
//Joseph Castelan
//jgcastel@ucsc.edu

//Cesar Neri
//ceneri@ucsc.edu

#include <assert.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "astree.h"
#include "string_set.h"
#include "lyutils.h"
#include "symbol_table.h"


astree::astree (int symbol_, const location& lloc_, const char* info) {
   symbol = symbol_;
   lloc = lloc_;
   //char *tname = (char*) parser::get_tname (symbol);
   //if (strstr (tname, "TOK_") == tname) tname += 4;
   //fprintf (outfile, " %*s", depth * 3, "");
   /*fprintf (stdout, "%s \"%s\" %zd.%zd.%zd\n",
            tname, info,
            lloc.filenr, lloc.linenr, lloc.offset);*/
 
   lexinfo = string_set::intern (info);
   attributes = 0;
   //attributes.set(ATTR_void);//this was used for testing print output
   block_num = 0;
   struct_t = NULL;

   // vector defaults to empty -- no children
}

astree::~astree() {
   while (not children.empty()) {
      astree* child = children.back();
      children.pop_back();
      delete child;
   }
   if (yydebug) {
      fprintf (stderr, "Deleting astree (");
      astree::dump (stderr, this);
      fprintf (stderr, ")\n");
   }
}

astree* astree::adopt (astree* child1, astree* child2, astree* child3) {
   if (child1 != nullptr) children.push_back (child1);
   if (child2 != nullptr) children.push_back (child2);
   if (child3 != nullptr) children.push_back (child3);
   return this;
}

astree* astree::adopt_sym (astree* child, int symbol_) {
   symbol = symbol_;
   return adopt (child);
}

astree* astree::change_sym (astree* root, int symbol) {
    root->symbol = symbol;
    return root;
}

void astree::dump_node (FILE* outfile) {
   fprintf (outfile, "%p->{%s %zd.%zd.%zd \"%s\":",
            this, parser::get_tname (symbol),
            lloc.filenr, lloc.linenr, lloc.offset,
            lexinfo->c_str());
   for (size_t child = 0; child < children.size(); ++child) {
      fprintf (outfile, " %p", children.at(child));
   }
}

void astree::dump_tree (FILE* outfile, int depth) {
   fprintf (outfile, "%*s", depth * 3, "");
   dump_node (outfile);
   fprintf (outfile, "\n");
   for (astree* child: children) child->dump_tree (outfile, depth + 1);
   fflush (nullptr);
}

void astree::dump (FILE* outfile, astree* tree) {
   if (tree == nullptr) fprintf (outfile, "nullptr");
                   else tree->dump_node (outfile);
}

string getAttrName( int index){
    switch(index){
        case ATTR_void:
            return "void";
        case ATTR_int:
            return "int";
        case ATTR_null: 
            return "null";
        case ATTR_string:
            return "string";
        case ATTR_struct:
            return "struct";
        case ATTR_array:
            return "array";
        case ATTR_function:
            return "function";
        case ATTR_variable:
            return "variable";
        case ATTR_field:
            return "field";
        case ATTR_typeid: 
            return "typeid";
        case ATTR_param:
            return "param";
        case ATTR_lval:
            return "lval";
        case ATTR_const:
            return "const";
        case ATTR_vreg:
            return "vreg";
        case ATTR_vaddr:
            return "vaddr";
        //case ATTR_bitset_size //This can't happen (outofbounds)
        //  return "(ERROR)bitset_size";
        default:
            return "ERROR";
    }
}

//printing must only happen after symbol table stuff is done
void astree::print (FILE* outfile, astree* tree, int depth) {
    if(tree == nullptr){return;} //prevent segfault on empty tree;
    if(tree == NULL){return;}
    char *tname = (char*) parser::get_tname (tree->symbol);
    //printf( "~~%s at depth:%d\n", tname, depth);
    if (strstr (tname, "TOK_") == tname) tname += 4;
   //fprintf (outfile, " %*s", depth * 3, "");
   for( int index = 0; index < depth; index++){
       fprintf( outfile, "|   ");
   }
   fprintf (outfile, "%s \"%s\" (%zd.%zd.%zd) {%zd} ",
            tname, tree->lexinfo->c_str(),
            tree->lloc.filenr, tree->lloc.linenr, tree->lloc.offset,
            tree->block_num);
    //bitsets work kind of like an array of 0s and 1s
    //we will check each entry in the bitset to find where 
    //every 1 appears. If there is a 1, then the node must have 
    //the attribute associated with that index.
    for( int index = 0; index < ATTR_bitset_size; index++){
        if( tree->attributes.test(index)){//check if bit is set
            fprintf( outfile, "%s ", getAttrName(index).c_str());
        }
    }
    
    //For identifiers, the last number is the coordinate of the declaration.
    //we're probably going to have to look it up in one of our tables
    //if( struct_t != NULL){
        //if( struct_t->attributes.test( 
    //}
    if( tree-> attributes.test( ATTR_variable)){
        size_t tempFilenr = find_ident( tree)->filenr;
        size_t tempLinenr = find_ident( tree)->linenr;
        size_t tempOffset = find_ident( tree)->offset;
        fprintf( outfile, " %zd.%zd.%zd ", tempFilenr, tempLinenr, tempOffset);
    }
    
    fprintf( outfile, "\n");
   for (astree* child: tree->children) { //prints the information of the next child
      astree::print (outfile, child, depth + 1);
   }
}

void destroy (astree* tree1, astree* tree2) {
   if (tree1 != nullptr) delete tree1;
   if (tree2 != nullptr) delete tree2;
}

void errllocprintf (const location& lloc, const char* format,
                    const char* arg) {
   static char buffer[0x1000];
   assert (sizeof buffer > strlen (format) + strlen (arg));
   snprintf (buffer, sizeof buffer, format, arg);
   errprintf ("%s:%zd.%zd: %s", 
              lexer::filename (lloc.filenr), lloc.linenr, lloc.offset,
              buffer);
}
