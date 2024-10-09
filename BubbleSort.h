#ifndef BUBBLE_SORT
#define BUBBLE_SORT

void Swap_size_t(size_t* n1, size_t* n2);
void Swap_strings(char** string_1, char** string_2);
bool IsLetter(char symbol);
int strcmp(char* string_1, char* string_2);
void Bubble_sort(char** strings, size_t* strlen, TheInputFile input_file);

#endif
