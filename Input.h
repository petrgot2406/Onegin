#ifndef INPUT
#define INPUT

#include "Struct.h"

size_t num_of_symbols_in_file(TheInputFile input_file);
size_t num_of_strings_in_file(TheInputFile input_file);
void Put_file_characteristics_to_structure(TheInputFile* input_file);
void Read_file_to_buffer(TheInputFile input_file, char* buffer);
void Put_lineslen_for_all_lines(char* buffer, TheInputFile input_file, size_t* lineslen);
void Put_pointers_to_lines(char* buffer, TheInputFile input_file, char** strings);

#endif
