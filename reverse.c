#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_utils.h"
#include <string.h>

/*****************************************************************
This is project 1 for CIS 343. It takes two file names, input and
output, and reverses the contents of the input file and puts them
into the output file.

@author Kehlsey Lewis
@version Fall 2018
*****************************************************************/

int main (int argc, char* argv[]){
	
	char *buffer; 
	int size;

	// names of the files to read/write
	char* read = argv[1];
	char* write = argv[2];


	size = read_file(read, &buffer); //opening file and getting the size


	// Got string reversal code snippet from
	// http://www.c4learn.com/c-programs/c-program-reverse-string-without-using.html
	char temp;
	int i = 0;
	int j = size - 2; //-2 to skip the null character

	while (i < j) {
		temp = buffer[i]; // temp holding the first char of buffer 
		buffer[i] = buffer[j]; // swaping the first char with the last
		buffer[j] = temp; // setting the last char = to the temp char
		i++; //increment i
		j--; //decrment j
	}
	
	write_file(write, buffer, size); // send  reversed buffer to write to file

	return 0;

}