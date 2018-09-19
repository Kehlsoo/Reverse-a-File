#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

/*****************************************************************
These are the definitions of the file utilities needed for reverse.c.

@author Kehlsey Lewis
@version Fall 2018
*****************************************************************/

 /** opens and reads the specified input file */
int read_file( char* filename, char **buffer );

 /** opens and writes to the specified output file */
int write_file( char* filename, char *buffer, int size);