// $Id: astree.h,v 1.10 2016-10-06 16:42:35-07 - - $
//Joseph Castelan
//jgcastel@ucsc.edu

//Cesar Neri
//ceneri@ucsc.edu

#ifndef __ASTREE_H__
#define __ASTREE_H__

#include <string>
#include <vector>
#include <bitset>
#include <unordered_map>
#include <utility>
using namespace std;

#include "auxlib.h"


enum { ATTR_void, ATTR_int, ATTR_null, ATTR_string,
	   ATTR_struct, ATTR_array, ATTR_function, ATTR_variable, 
	   ATTR_field, ATTR_typeid, ATTR_param, ATTR_lval, ATTR_const,
	   ATTR_vreg, ATTR_vaddr, ATTR_bitset_size,
};
struct symbol;

using attr_bitset = bitset<ATTR_bitset_size>;
using symbol_table = unordered_map<string*, symbol*>;
//using symbol_entry = symbol_table::value_type;

struct location {
   size_t filenr;
   size_t linenr;
   size_t offset;
};

struct astree {

   // Fields.
   int symbol;               // token code
   location lloc;            // source location
   const string* lexinfo;    // pointer to lexical information
   vector<astree*> children; // children of this n-way node
   attr_bitset attributes;
   size_t block_num;
   symbol_table* struct_t;


   // Functions.
   astree (int symbol, const location&, const char* lexinfo);
   ~astree();
   astree* adopt (astree* child1, astree* child2 = nullptr, 
                    astree* child3 = nullptr);
   astree* adopt_sym (astree* child, int symbol);
   astree* change_sym (astree* root, int symbol); 
   void dump_node (FILE*);
   void dump_tree (FILE*, int depth = 0);
   static void dump (FILE* outfile, astree* tree);
   static void print (FILE* outfile, astree* tree, int depth = 0);
};

void destroy (astree* tree1, astree* tree2 = nullptr);

void errllocprintf (const location&, const char* format, const char*);

string getAttrName( int index);
#endif

