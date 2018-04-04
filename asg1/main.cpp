/* 
 * main.cpp
 * Cesar Neri 1513805
 *
 * Created on October 13, 2017, 9:25 PM
 * 
 * Main.cpp reads and validate appropiate filename and runs in 
 * trough the CPP.
 * It then adds token to the string set and print table to
 *  filename.str
 */

#include <string>
using namespace std;

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <libgen.h>

#include "string_set.h"
#include "auxlib.h"

const string CPP = "/usr/bin/cpp -nostdinc";        /*CPP location*/
constexpr size_t LINESIZE = 1024;

/*
 *  Chomp the last character from a buffer if it is delim.
 * Function chomp() is called by cpplines()
 */
void chomp (char* string, char delim) {
   size_t len = strlen (string);
   if (len == 0) return;
   char* nlpos = string + len - 1;
   if (*nlpos == delim) *nlpos = '\0';
}

/*
 * Run cpp against the lines of the file.
 * As obtained from cppstrtok.cpp and modified to add each 
 * token to string table.
 * by calling string_set::intern ()
 */
void cpplines (FILE* pipe, const char* filename) {
   int linenr = 1;
   char inputname[LINESIZE];
   strcpy (inputname, filename);
   for (;;) {
      char buffer[LINESIZE];
      char* fgets_rc = fgets (buffer, LINESIZE, pipe);
      if (fgets_rc == NULL) break;
      chomp (buffer, '\n');
      //printf ("%s:line %d: [%s]\n", filename, linenr, buffer);
      // http://gcc.gnu.org/onlinedocs/cpp/Preprocessor-Output.html
      int sscanf_rc = sscanf (buffer, "# %d \"%[^\"]\"",
                              &linenr, inputname);
      if (sscanf_rc == 2) {
         //printf ("DIRECTIVE: line %d file \"%s\"\n", linenr, 
         ////inputname);
         continue;
      }
      char* savepos = NULL;
      char* bufptr = buffer;
      for (int tokenct = 1;; ++tokenct) {
         char* token = strtok_r (bufptr, " \t\n", &savepos);
         bufptr = NULL;
         if (token == NULL) break;
         //printf ("token %d.%d: [%s]\n",
                 //linenr, tokenct, token);
         
         //Save current token to string_table
         string_set::intern (token);
         
      }
      ++linenr;
   }
}

int main (int argc, char** argv) {
    
    int arg;                    /*Used to iterate trough arguments*/
    string d_string = "";       /*CPP argument to be passed*/
    
    //Flags to be used letter for flex and bison flags
    //int l_flag = 0;
    //int y_flag = 0;
    
    //Allows proper used of eprintf() and its assertions
    exec::execname = basename (argv[0]);
    
    /*Get file name and validate it*/
    string file_name = argv[argc-1];
 
    int file_size = file_name.size();
    
    //Check that a file name was passed
    if(optind >= argc){
            eprintf("Error: Input filename not found\n");
            return EXIT_FAILURE;
    }
    
    //Check that a valid filename is passed
    if ( file_size <= 3){
        eprintf("Error: Invalid filename\n");
        return EXIT_FAILURE;
    }
    
    //Check that a valid extension is passed
    if (file_name.substr( file_size -3, 3) != ".oc"){
        eprintf("Error: Invalid file extension\n");
        exit (EXIT_FAILURE);
        //return EXIT_FAILURE;
    }
   
    /*Look at arguments passed and modify accordingly*/
    while ((arg = getopt (argc, argv, "@:D:ly")) != -1){
        switch (arg){
            case '@':
                set_debugflags(optarg);
                break;
            case 'D':
                d_string = " -D" + string(optarg);
                break;
            case 'l':
                //l_flag = 1;
                break;
            case 'y':
                //y_flag = 1;
                break;
            /*case '?':
                if (optopt == '@')
                    errprintf("%: Option -%c requires an argument.\n", 
optopt);
                else if (isprint (optopt))
                    errprintf("Unknown option `-%c'.\n", optopt);
                else
                    errprintf("Unknown option character `\\x%x'.\n", 
optopt);
                return 1;*/
            default:
                errprintf("%: Invalid option \n", optopt);
                //abort ();
        }
    }

    //Create filename and pointer of output file (.str)
    string out_file = file_name.substr(0, file_name.size()-3) + ".str";
    FILE *out_file_ptr  = fopen(out_file.c_str(), "w");
    
    //CPP command as used in cppstrtok.cpp sample
    string command = CPP + d_string + " " + file_name;
    
    //Call to cpplines() and tokens into strig set table
    FILE* pipe = popen (command.c_str(), "r");
    if (pipe == NULL) {
        exec::exit_status = EXIT_FAILURE;
        fprintf (stderr, "%s: %s: %s\n",
        exec::execname.c_str(), command.c_str(), strerror (errno));
    }else {
        cpplines (pipe, file_name.c_str());
        int pclose_rc = pclose (pipe);
        eprint_status (command.c_str(), pclose_rc);
        if (pclose_rc != 0) exec::exit_status = EXIT_FAILURE;
    }

    //Call to string_set::dump() print to output file
    string_set::dump(out_file_ptr);          
    fclose(out_file_ptr);

   return EXIT_SUCCESS;
}
