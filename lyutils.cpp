// $Id: lyutils.cpp,v 1.3 2016-10-06 16:42:35-07 - - $
//Joseph Castelan
//jgcastel@ucsc.edu

//Cesar Neri
//ceneri@ucsc.edu

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "auxlib.h"
#include "lyutils.h"

//Output tok file
extern FILE* toke_file;

bool lexer::interactive = true;
location lexer::lloc = {0, 1, 0};
size_t lexer::last_yyleng = 0;
vector<string> lexer::filenames;

astree* yyparse_astree = NULL;
astree* parser::root = nullptr;

const string* lexer::filename (int filenr) {
   return &lexer::filenames.at(filenr);
}
astree* emptyTree (void) {
    parser::root = new astree (TOK_ROOT, {0,0,0} , "");
    return parser::root;
}

void lexer::newfilename (const string& filename) {
    lexer::lloc.filenr = lexer::filenames.size();
    lexer::filenames.push_back (filename);
    
    //Print file included
    fprintf(toke_file, "# %2zu  \"%s\" \n", 
            lexer::filenames.size(), filename.c_str());
}

void lexer::advance() {
   if (not interactive) {
      if (lexer::lloc.offset == 0) {
         printf (";%2zd.%3zd: ",
                 lexer::lloc.filenr, lexer::lloc.linenr);
      }
      printf ("%s", yytext);
   }
   lexer::lloc.offset += last_yyleng;
   last_yyleng = yyleng;
}

void lexer::newline() {
   ++lexer::lloc.linenr;
   lexer::lloc.offset = 0;
}

void lexer::badchar (unsigned char bad) {
   char buffer[16];
   snprintf (buffer, sizeof buffer,
             isgraph (bad) ? "%c" : "\\%03o", bad);
   errllocprintf (lexer::lloc, "invalid source character (%s)\n",
                  buffer);
}

void lexer::badtoken (char* lexeme) {
   errllocprintf (lexer::lloc, "invalid token (%s)\n", lexeme);
}

void lexer::include() {
   size_t linenr;
   static char filename[0x1000];
   assert (sizeof filename > strlen (yytext));
   int scan_rc = sscanf (yytext, "# %zd \"%[^\"]\"", &linenr, filename);
   if (scan_rc != 2) {
      errprintf ("%s: invalid directive, ignored\n", yytext);
   }else {
      lexer::lloc.linenr = linenr - 1;
      lexer::newfilename (filename);
   }
}

void yyerror (const char* message) {
   assert (not lexer::filenames.empty());
   errllocprintf (lexer::lloc, "%s\n", message);
}

/*Creates a tree for corresponding token and returns symbol*/
int yylval_token (int symbol) {
    yylval= new astree(symbol, lexer::lloc, yytext);
    fprintf(toke_file, "%4zu %3zu.%03zu  %-3d  %-15s (%-s)\n", 
            lexer::filenames.size(), lexer::lloc.linenr, 
            lexer::lloc.offset, symbol, parser::get_tname(symbol), 
            yytext);
   return symbol;
}

