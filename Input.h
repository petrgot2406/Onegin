#ifndef INPUT
#define INPUT

struct TheInputFile
{
    const char* input_file_name;
    size_t file_size;
    size_t str_num;
    size_t max_str_len;
};

size_t num_of_symbols_in_file(TheInputFile input_file);
size_t num_of_strings_in_file(TheInputFile input_file);
size_t max_strlen_of_file(TheInputFile input_file);
void Read_file_to_buffer(TheInputFile input_file, char* buffer);
void Put_strlen_for_all_strings(char* buffer, TheInputFile input_file, size_t* strlen);
void Put_pointers_to_strings(char* buffer, TheInputFile input_file, char** strings);

#endif
