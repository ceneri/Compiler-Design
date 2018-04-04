%{
// $Id: parser.y,v 1.11 2017-10-11 14:27:30-07 - - $
// Dummy parser for scanner project.
//Joseph Castelan
//jgcastel@ucsc.edu

//Cesar Neri
//ceneri@ucsc.edu

#include <cassert>

#include "lyutils.h"
#include "astree.h"

%}

%debug
%defines
%error-verbose
%token-table
%verbose

%token TOK_VOID TOK_CHAR TOK_INT TOK_STRING
%token TOK_IF TOK_ELSE TOK_WHILE TOK_RETURN TOK_STRUCT
%token TOK_NULL TOK_NEW TOK_ARRAY
%token TOK_EQ TOK_NE TOK_LT TOK_LE TOK_GT TOK_GE
%token TOK_IDENT TOK_INTCON TOK_CHARCON TOK_STRINGCON

%token TOK_BLOCK TOK_CALL TOK_IFELSE TOK_INITDECL
%token TOK_POS TOK_NEG TOK_NEWARRAY TOK_TYPEID TOK_FIELD
%token TOK_ORD TOK_CHR TOK_ROOT

%token TOK_DECLID TOK_PARAMLIST TOK_FUNCTION TOK_PROTOTYPE
%token TOK_VARDECL TOK_RETURNVOID TOK_NEWSTRING TOK_INDEX

%token  '('  ')'  '['  ']'  '{'  '}'  ';'  ','  '.'
%token  '='  '+'  '-'  '*'  '/'  '%'  '!'

%right      TOK_IF TOK_ELSE
%right      '='
%left       TOK_EQ TOK_NE TOK_LT TOK_LE TOK_GT TOK_GE
%left       '+' '-'
%left       '*' '/' '%'
%right      TOK_POS TOK_NEG '!' TOK_NEW
%left       TOK_ARRAY TOK_FIELD TOK_CALL 
%left       '[' '.'
%nonassoc   '('  
//%nonassoc   TOK_PARENT

%start start

%%

start       : program           { yyparse_astree = $1; }
            ;
            
program     : program structdef  { $$ = $1->adopt ($2); }
            | program function  { $$ = $1->adopt ($2); }
            | program statement { $$ = $1->adopt ($2); }
            | program error '}' { $$ = $1; }
            | program error ';' { $$ = $1; }
            |                   { $$ = emptyTree(); }
            ;
            
structdef   : TOK_STRUCT TOK_IDENT fielddecls '}'  
                { $2 = $2 ->change_sym($2, TOK_TYPEID);     
                  $$ = $1 -> adopt ($2, $3); 
                  destroy($4);
                }  
            | TOK_STRUCT TOK_IDENT '{' '}'  
                { $2 = $2 ->change_sym($2, TOK_TYPEID);
                  $$ = $1 -> adopt ($2);
                  destroy($4);
                  destroy($3);
                }
            ;
            
fielddecls  : fielddecls fielddecl ';'     { $$ = $1->adopt($2); 
                                            destroy($3);}
            | '{' fielddecl ';'             { $$ = $1->adopt($2); 
                                            destroy($3);}
            ;
            
fielddecl   : basetype TOK_ARRAY TOK_IDENT 
                { $3 = $3 ->change_sym($3, TOK_FIELD);     
                  $$ = $2 ->adopt ($1, $3); 
                }
            | basetype TOK_IDENT 
                { $2 = $2 ->change_sym($2, TOK_FIELD);     
                  $$ = $1 ->adopt ($2); 
                }
            ;
            
basetype    : TOK_VOID      { $$ = $1; }
            | TOK_INT       { $$ = $1; }   
            | TOK_STRING    { $$ = $1; }
            | TOK_CHAR      { $$ = $1; }
            | TOK_IDENT     { $$ = $1 ->change_sym($1, TOK_TYPEID);}
            ;
            
function    : identdecl params ')' block
                { destroy($3);
                  $$ = new astree(TOK_FUNCTION, $1->lloc, "");
                  $$ = $$->adopt($1, $2, $4);
                }
            | identdecl '(' ')' block
                { $2 = $2 ->change_sym($2, 
                        TOK_PARAMLIST);                   
                  $$ = new astree(TOK_FUNCTION, 
                        $1->lloc, "");
                  $$ = $$->adopt($1, $2, $4);
                  destroy($3);
                }
            | identdecl params ')' ';'
                  {destroy($3);
                  destroy($4);
                  $$ = new astree(TOK_PROTOTYPE, $1->lloc, "");
                  $$ = $$->adopt($1, $2);
                } 
            | identdecl '(' ')' ';'
                { $2 = $2 ->change_sym($2, 
                    TOK_PARAMLIST);                    
                  $$ = new astree(TOK_PROTOTYPE,
                    $1->lloc, "");
                  $$ = $$->adopt($1, $2);
                  destroy($3);
                  destroy($4);
                }
            ;
            
params      : params ',' identdecl 
                { $$ = $1->adopt($3); 
                  destroy($2);
                }
            | '(' identdecl             
                { $1 = $1 ->change_sym($1, TOK_PARAMLIST);
                  $$ = $1->adopt($2); 
                }
            ;
            
identdecl   : basetype TOK_ARRAY TOK_IDENT                       
                { $3 = $3 ->change_sym($3, 
                    TOK_DECLID);                    
                  $$ = $2 -> adopt($1, $3);
                }
            | basetype TOK_IDENT 
                { $2 = $2 ->change_sym($2, 
                    TOK_DECLID);                    
                  $$ = $1 -> adopt($2);
                }
            ;
            
block       :  statements '}'
                {                   
                  $$ = $1;
                  destroy($2);
                }
            | '{' '}'
                { $1 = $1 ->change_sym($1, 
                    TOK_BLOCK);
                    $$ = $1;
                  destroy($2);
                }
            |  ';'  {destroy($1);}
            ;
            
statements  :  statements statement         
                { $$ = $1->adopt($2); }                     
            |  '{' statement                
                { $1 = $1 ->change_sym($1, 
                    TOK_BLOCK);  
                $$ = $1->adopt($2); 
                }
            ;
            

statement   :  block                    { $$ = $1; }
            |  vardecl                  { $$ = $1; }                
            |  while                    { $$ = $1; }  
            |  ifelse                   { $$ = $1; }
            |  return                   { $$ = $1; }
            |  expr ';'                 { $$ = $1; destroy($2);}
            ;

vardecl     : identdecl '=' expr ';'
                { $2 = $2 ->change_sym($2, TOK_VARDECL);        
                  $$ = $2 ->adopt($1, $3);
                }
            ;

while       : TOK_WHILE '(' expr ')' statement         
                { $$ = $1 ->adopt($3, $5);
                  destroy($2);
                  destroy($4);
                }
            ;
   
ifelse      : TOK_IF '(' expr ')' statement 
                { $$ = $1 ->adopt($3, $5);
                destroy($2);
                destroy($4);
                }
            | TOK_IF '(' expr ')' statement TOK_ELSE statement
                { $1 = $1 ->change_sym($1, 
                    TOK_IFELSE);                  
                  $$ = $1 ->adopt($3, $5, $7);
                  destroy($2);
                  destroy($4);
                }
            ;
            
return      : TOK_RETURN ';'
                { $$ = $1 ->change_sym($1, TOK_RETURNVOID);
                  destroy($2);
                }
            | TOK_RETURN expr ';'
                { $$ = $1 ->adopt($2);
                destroy($3);
                }
            ;
            
expr        : binop                     { $$ = $1; }
            | unop                      { $$ = $1; }
            | allocator                 { $$ = $1; }
            | call                      { $$ = $1; }
            | '(' expr ')'              { $$ = $2; 
                                          destroy($1);
                                          destroy($3);}
            | variable                  { $$ = $1; }
            | constant                  { $$ = $1; }
            ;
            
binop       : expr '=' expr             { $$ = $2 ->adopt($1, $3); }
            | expr TOK_EQ expr          { $$ = $2 ->adopt($1, $3); }
            | expr TOK_NE expr          { $$ = $2 ->adopt($1, $3); }
            | expr TOK_LT expr          { $$ = $2 ->adopt($1, $3); }
            | expr TOK_LE expr          { $$ = $2 ->adopt($1, $3); }
            | expr TOK_GT expr          { $$ = $2 ->adopt($1, $3); }
            | expr TOK_GE expr          { $$ = $2 ->adopt($1, $3); }
            | expr '+' expr             { $$ = $2 ->adopt($1, $3); }
            | expr '-' expr             { $$ = $2 ->adopt($1, $3); }
            | expr '*' expr             { $$ = $2 ->adopt($1, $3); }
            | expr '/' expr             { $$ = $2 ->adopt($1, $3); }
            | expr '%' expr             { $$ = $2 ->adopt($1, $3); }
            ;
            
unop        : '+' expr                  { $1 = $1 ->change_sym($1, 
                                            TOK_POS); 
                                          $$ = $1 ->adopt($2); 
                                        }
            | '-' expr                  { $1 = $1 ->change_sym($1, 
                                            TOK_NEG); 
                                          $$ = $1 ->adopt($2); 
                                        }
            | '!' expr                  { $$ = $1 ->adopt($2); }
            | TOK_NEW expr              { $$ = $1 ->adopt($2); }
            ;

allocator   : TOK_NEW TOK_IDENT '(' ')'
                { $2 = $2 ->change_sym($2, TOK_TYPEID);
                  $$ = $1 ->adopt($2);
                  destroy($3);
                  destroy($4);
                }
            | TOK_NEW TOK_STRING '(' expr ')'
                { $1 = $1 ->change_sym($1, TOK_NEWSTRING);
                  $$ = $1 ->adopt($4);
                  destroy($3);
                  destroy($5);
                }
            | TOK_NEW basetype '[' expr ']'
                { $1 = $1 ->change_sym($1, TOK_NEWARRAY);
                  $$ = $1 ->adopt($2, $4);
                  destroy($3);
                  destroy($5);
                }
            ;   

call        : TOK_IDENT '(' ')'      { $2 ->change_sym($2, TOK_CALL);
                                       destroy( $3 );
                                       $$=$2->adopt($1);
                                     }
            |  multiexpr ')'         {$$=$1; destroy($2);}
            ;
            
multiexpr   : multiexpr ',' expr    { destroy($2);
                                      $$ = $1->adopt($3);
                                    }
            | TOK_IDENT '(' expr    { $2 ->change_sym($2, TOK_CALL); 
                                      $$ = $2->adopt($1,$3); }
            ;

variable    : TOK_IDENT             { $$ = $1;}
            | expr '[' expr ']'     { $2 = $2 ->change_sym($2, 
                                        TOK_INDEX);
                                      destroy($4);
                                      $$ = $2->adopt($1, $3);
                                    }
            | expr '.' TOK_IDENT    { $3 = $3->change_sym($3,TOK_FIELD);

                                      $$ = $2->adopt($1, $3);}
            ;
            
constant    : TOK_INTCON            { $$ = $1; }
            | TOK_CHARCON           { $$ = $1; }
            | TOK_STRINGCON         { $$ = $1; }
            | TOK_NULL              { $$ = $1; }
            ;
            

%%

const char *parser::get_tname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}


bool is_defined_token (int symbol) {
   return YYTRANSLATE (symbol) > YYUNDEFTOK;
}

/*
static void* yycalloc (size_t size) {
   void* result = calloc (1, size);
   assert (result != nullptr);
   return result;
}
*/
