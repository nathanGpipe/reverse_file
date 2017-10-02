/**
 * Interface for read/write functionality for the file
 * reversal program.
 *
 * Author: Nathan Pipe
 */

#ifndef H_FILE_UTILS
#define H_FILE_UTILS

/**
 * Takes the input of a string, filename, and a string pointer
 * which the contents of the file read will be dumped into.
 * Returns the number of bytes read, -1 if an error occured.
 */
int read_file(char* filename, char** buffer);

/**
 * Writes the contents of a string backwards into a file.
 * Takes the input of a string, filename, a string containing what
 * to be written to the file, buffer, and an integer denoting the 
 * size of buffer.
 * Returns the number of bytes written, -1 if an error occured.
 */
int write_file(char* filename, char* buffer, int size);

#endif
