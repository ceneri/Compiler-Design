
#ifndef __SYMBOL_TABLE_H__
#define __SYMBOL_TABLE_H__

#include<vector>
#include <bitset>
#include <unordered_map>
using namespace std;

#include "string_set.h"
#include "astree.h"
#include "lyutils.h"

//struct symbol;


//using attr_bitset = bitset<ATTR_bitset_size>;
//using symbol_table = unordered_map<string*, symbol*>;
using symbol_entry = symbol_table::value_type;  /*pair<string,symbol>*/

struct symbol{
    attr_bitset attributes;
    symbol_table* fields; //used for struct types
    size_t filenr, linenr, offset;
    size_t block_nr;
    vector<symbol*>* parameters;
};

symbol* find_ident(astree* node); //might use it in astree.cpp
//does all the symbol table stuff
void initialize_tables(FILE* symFile, astree* root); 
#endif
