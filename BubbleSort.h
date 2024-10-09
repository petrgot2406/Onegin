#ifndef BUBBLE_SORT
#define BUBBLE_SORT

void Swap_size_t(size_t* n1, size_t* n2);
void Swap_strings(char** string_1, char** string_2);
bool IsLetter(char symbol);
size_t length_of_the_string(char* string);
int strcmp(char* string_1, char* string_2);
int strcmp_reverse(char* string_1, char* string_2);
void Bubble_sort(char** strings, size_t* strlen, TheInputFile input_file);
void Bubble_sort_reverse(char** strings, size_t* strlen, TheInputFile input_file);

#endif
