//Joseph Castelan
//jgcastel@ucsc.edu

//Cesar Neri
//ceneri@ucsc.edu
 
#include <string>
using namespace std;

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>
#include <wait.h>
#include <unistd.h>

#include "astree.h"
#include "auxlib.h"
#include "lyutils.h"
#include "string_set.h"

const string CPP = "/usr/bin/cpp -nostdinc";
constexpr size_t LINESIZE = 1024;

int lFlag;
int yFlag;
char* atFlag;
char* dOptions;

FILE *toke_file;
extern astree *yyparse_astree;

//Read trough arguments provided and handle flags accordingly
void read_flags(int argc, char** argv){   
    char readOpt;
    
    //This while loop handles the flags
    while( (readOpt = getopt( argc, argv, "ly@:D:")) != -1){
        switch( readOpt){
            case 'l':
                lFlag=1;
                yy_flex_debug = 1;
                break;
            case 'y':
                yFlag=1;
                yydebug = 1;
                break;
            case '@':
                break;
            case 'D':
                dOptions = optarg;
                break;
            default:
                break;
        }//end switch
    }//end while
    
}

//Opens scanner iput file to read from filenam after 
//going through  CPP
void set_scanner(char* filename){
    string command;
    
    //command to run through CPP
    if( dOptions != 0){
        command = CPP + " -D" + dOptions + " " + filename;
    }else{
        command = CPP + " " + filename;
    }
       
    //Set and open flex input file
    yyin = popen (command.c_str(), "r");
    if (yyin == nullptr) {
        syserrprintf (command.c_str());
        exit (exec::exit_status);
    } else {
        if (lFlag) {
            /*!!Turn on option DEBUG*/
            fprintf (stderr, 
                "-- popen (%s), fileno(yyin) = %d\n",
                command.c_str(), fileno (yyin));
        }
                    
    }
}

//Opens and closes corresponding tok, str, and ast output files
//yyparse() internally calls yylex() and handles adding to stringset
//Contents of table are dumped to "str" file
//After yyparse() is finished, it is safe to print the tree
void run_scanner(string file_name){
    
    //Defines str a tok destination files
    string tokFileName = file_name + ".tok";
    string strFileName = file_name + ".str";
    string astFileName = file_name + ".ast";
    
    //Open tok output file
    toke_file = fopen(tokFileName.c_str(), "w");
    if (toke_file == NULL) {
        syserrprintf (tokFileName.c_str());
        exec::exit_status = EXIT_FAILURE;
    }    

    //Used yyparse() once instead of multiple calls to yylex()
    //The value returned by yyparse() indicates if anything went wrong 
    //printf( "A\n");
    int statusVal;
    statusVal = yyparse();
    if( statusVal != 0){
        printf( "\t~~~~~SOME ERROR OCCURRED when using yyparse~~~~~\n");
    }
    //printf( "B\n");
    //Close pipe
    int pclose_rc = pclose (yyin);
    if (pclose_rc != 0) exec::exit_status = EXIT_FAILURE; 
    //printf( "C\n");
    //Open str file and dump string_set
    FILE * newFile;
    newFile = fopen( strFileName.c_str(), "w");
    string_set::dump (newFile);
    //printf( "D\n");
    //Close tok and str files
    fclose (newFile); 
    fclose (toke_file);
    //printf( "E\n");
    //open .ast file and dump the tree
    FILE * astFile;
    //printf( "F\n");
    astFile = fopen( astFileName.c_str(), "w");
    //printf( "G\n");
    astree::print( astFile, yyparse_astree);
    //printf( "H\n");
    fclose(astFile);
    //printf( "I\n");
}

int main (int argc, char** argv) {
    const char* execname = basename (argv[0]);
    int exit_status = EXIT_SUCCESS;

    //Argument Flags/Options
    lFlag = 0;
    yFlag = 0;
    atFlag = 0;
    dOptions = 0;

    yy_flex_debug = 0;
    yydebug = 0;

    char* base;
    size_t baseLen = 0;
    
    //Call to read and handle flags
    read_flags(argc, argv);

    //This part loops through all the args
    for (int argi = 1; argi < argc; ++argi) {
        char* filename = argv[argi];

        //This if statement makes sure filename[0] exists
        if( strlen(filename) >= 2){
            char namePrefix = filename[0];

            if( '-' == namePrefix ){
                //This means we are looking at a flag
                //flags were dealt with earlier, so we do nothing here
            }else{
                //This means we are likely looking at a file name
                base = basename( filename);
                baseLen = strlen( base);
                string sBase( base );
                int suffLen = baseLen-3;

                if( baseLen <=3){
                    //This means that the file name is not long enough.
                    //It has to be larger than 3 characters because
                    //.oc has 3 characters
                    fprintf (stderr, "%s: %s: %s\n",
                        execname, "File name too short", 
                        strerror (errno));
 
                    exit(EXIT_FAILURE);
                }

                if( sBase.find( ".oc", suffLen) == string::npos){
                    //This means the file name does not end in .oc
                    //the find function above is configured to search
                    //for ".oc" in the last part of the file name
                    fprintf (stderr, "%s: %s: %s\n",
                        execname, "Wrong file ending", 
                        strerror (errno));

                    exit(EXIT_FAILURE);
                }

                char suffix[1024];
                memcpy( &suffix, base, suffLen);//copies "real" name
                string newFileName(suffix);

                //Set and open flex to read from filename as input file
                set_scanner(filename);

                //Run scanner and generate "str" and "tok" files
                run_scanner(newFileName);

            }//end else
        }//end if
    }//end for

    return exit_status;

}//end main()
