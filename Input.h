#ifndef INPUT
#define INPUT

#include "Struct.h"

size_t num_of_symbols_in_file(TextOrig original_text);
size_t num_of_strings_in_file(TextOrig original_text);
void Put_file_characteristics_to_structure(TextOrig* original_text);
void Read_file_to_buffer(TextOrig* original_text);
void Put_lineslen_for_all_lines(TextOrig original_text, TextSort* sorted_text);
void Put_pointers_to_lines(TextOrig original_text, TextSort* sorted_text);
void Put_inputfile_to_structure(Text* the_text);

#endif
