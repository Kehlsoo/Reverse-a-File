#include "file_utils.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

/*****************************************************************
These are the file utilities needed to open and write files in
reverse.c.

@author Kehlsey Lewis
@version Fall 2018
*****************************************************************/



/****************************************************************
 opens and reads the specified input file 
 ***************************************************************/
int read_file( char* filename, char **buffer ){

	// creates a file to read
	FILE* fin = fopen(filename, "r");

	// determines size
	struct stat st;
	stat(filename, &st);
	int size = st.st_size;

	//error checking for null file
	if (fin == NULL){
		printf("File failed to open\nMake sure you specified a input file!\n");
	}

	//opens file if found
	else if (fin != NULL){	

		*buffer = (char*)malloc((size + 1) * sizeof(char));
		fread(*buffer, size, sizeof(char), fin);
		fclose(fin);
	}

	//catches other errors
	else {
		fprintf( stderr, "ERROR MESSAGE" );
	}

	return size;
}

/****************************************************************
 opens and writes to the specified output file
***************************************************************/
int write_file( char* filename, char *buffer, int size){


	 // creates a file to write to
	FILE *fout = fopen(filename, "w");

    // error check for null file
	if(fout == NULL) {
		printf("File failed to open\nMake sure you specified an output file!\n");
	} 

	//write buffer to the specified file
	else if (fout != NULL){
		fprintf(fout, "%s", buffer);
		fclose(fout);
	}

	//catches other errors
	else {
		fprintf( stderr, "ERROR MESSAGE" );
	}

	return 1;
}