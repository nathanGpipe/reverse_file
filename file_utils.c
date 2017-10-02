#include "file_utils.h"
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>


/*
	Takes a file on the system at filename, and places into the buffer.
	Returns the number of bytes read.
*/
int read_file(char* filename, char** buffer) {
	FILE* fp = fopen(filename, "r");
	if(fp == NULL) {
		fprintf(stderr, "\nError: File doesn't exist");
		return -1;
	}

	//get size
	struct stat st;
	stat(filename, &st);
	int size = st.st_size;
	
	//allocate buffer
	*buffer = (char*)malloc(size);
	
	if(buffer == NULL)
		fprintf(stderr, "\nProblem allocating memory");
	else
		fread(*buffer, 1, size, fp);
	
	fclose(fp);
	return size;
}
	
/*
	Takes a buffer with size number of bytes and writes it to the system at filename.
	Returns the number of bytes written.
*/
int write_file(char* filename, char* buffer, int size) {
	FILE* fp = fopen(filename, "w");
	if(fp == NULL) {
		fprintf(stderr, "ERROR: Problem allocating memory");
	}
		
	int sizeWritten = 0;
	for (int i = size-1; i >= 0; i--) {
		//fputc(buffer[i], fp);
		char* c = buffer + i;
		fprintf(fp, "%c", *c);
		sizeWritten++;
	}
	
	fclose(fp);
	return -1;
}
