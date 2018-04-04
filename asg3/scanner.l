%{
//Joseph Castelan
//jgcastel@ucsc.edu

//Cesar Neri
//ceneri@ucsc.edu
#include "lyutils.h"

#define YY_USER_ACTION  { lexer::advance(); }

%}

%option 8bit
%option nodefault
%option noinput
%option debug
%option nounput
%option noyywrap
%option warn
%option verbose

LETTER          [A-Za-z_]
DIGIT           [0-9]
TOK_INTCON      ({DIGIT}+)
TOK_IDENT       ({LETTER}({LETTER}|{DIGIT})*)
TOK_CHARCON     ('([^\\'\n]|\\[\\'"0nt])')
TOK_STRINGCON   (\"([^\\"\n]|\\[\\'"0nt])*\")
NOTIDENT        ({DIGIT}({LETTER}|{DIGIT})*)
NOTCHAR         ('([^\\'\n]|\\[\\'"0nt]))
NOTSTRING       (\"([^\\"\n]|\\[\\'"0nt])*)

%%

"#".*           { lexer::include(); }
[ \t]+          { }
\n              { lexer::newline(); }

"+"             { return yylval_token ('+'); }
"-"             { return yylval_token ('-'); }
"*"             { return yylval_token ('*'); }
"/"             { return yylval_token ('/'); }
"%"             { return yylval_token ('%'); }
"!"             { return yylval_token ('!'); }
"="             { return yylval_token ('='); }
"<"             { return yylval_token (TOK_LT); }
">"             { return yylval_token (TOK_GT); }
","             { return yylval_token (','); }
"."             { return yylval_token ('.'); }
";"             { return yylval_token (';'); }
"("             { return yylval_token ('('); }
")"             { return yylval_token (')'); }
"["             { return yylval_token ('['); }
"]"             { return yylval_token (']'); }
"{"             { return yylval_token ('{'); }
"}"             { return yylval_token ('}'); }

"=="            { return yylval_token (TOK_EQ); }
"!="            { return yylval_token (TOK_NE); }
"<="            { return yylval_token (TOK_LE); }
">="            { return yylval_token (TOK_GE); }
"[]"            { return yylval_token (TOK_ARRAY); }

"if"            { return yylval_token (TOK_IF); }
"else"          { return yylval_token (TOK_ELSE); }
"while"         { return yylval_token (TOK_WHILE); }
"return"        { return yylval_token (TOK_RETURN); }
"int"           { return yylval_token (TOK_INT); }
"char"           { return yylval_token (TOK_CHAR); }
"string"        { return yylval_token (TOK_STRING); }
"struct"        { return yylval_token (TOK_STRUCT); }
"void"          { return yylval_token (TOK_VOID); }
"new"           { return yylval_token (TOK_NEW); }
"null"          { return yylval_token (TOK_NULL); }

{TOK_INTCON}    { return yylval_token (TOK_INTCON); }
{TOK_CHARCON}   { return yylval_token (TOK_CHARCON); }
{TOK_STRINGCON} { return yylval_token (TOK_STRINGCON); }
{TOK_IDENT}     { return yylval_token (TOK_IDENT); }


{NOTIDENT}     { lexer::badtoken (yytext);
                  return yylval_token (TOK_IDENT); }
{NOTCHAR}     { lexer::badtoken (yytext);
                  return yylval_token (TOK_CHARCON); }
{NOTSTRING}     { lexer::badtoken (yytext);
                  return yylval_token (TOK_STRINGCON); }
.               { lexer::badchar (*yytext); }

%%
