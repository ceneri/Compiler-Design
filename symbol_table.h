
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
	symbol_table* fields;
	size_t filenr, linenr, offset;
	size_t block_nr;
	vector<symbol*>* parameters;
};

symbol* find_ident(astree* node); //I put this here because I might use it in astree.cpp
void initialize_tables(FILE* symFile, astree* root); //does all the symbol table stuff
#endif