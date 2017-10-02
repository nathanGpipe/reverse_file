/**
 * Main function for the file reversal program,
 * handles commandline i/o
 *
 * Author: Nathan Pipe
 */

#include "file_utils.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	if(argc != 3) {
		printf("Invalid number of arguments\n");
		printf("Use format \"reverse <filename_in> <filename_out>\"");
		return -1;
	}
	
	char* buffer;
	int sizeRead = read_file(argv[1], &buffer);
	//printf(buffer);
	
	int sizeWritten = write_file(argv[2], buffer, sizeRead);
	//printf(buffer);	
	//error in file i/o
	if(sizeWritten != sizeRead)
		return -1;

	free(buffer);
	return 0;
}
