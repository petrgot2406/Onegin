#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Struct.h"
#include "Input.h"

size_t num_of_symbols_in_file(TheInputFile input_file)
{
    assert(input_file.input_file_name != NULL);
    FILE *fptr = fopen(input_file.input_file_name, "r");
    size_t counter = 0;
    while (getc(fptr) != EOF)
    {
        counter++;
    }
    fclose(fptr);
    return counter;
}

size_t num_of_strings_in_file(TheInputFile input_file)
{
    assert(input_file.input_file_name != NULL);
    FILE *fptr = fopen(input_file.input_file_name, "r");
    size_t counter = 0;
    int ch = getc(fptr);
    while (ch != EOF)
    {
        if (ch == '\n')
        {
            counter++;
        }
        ch = getc(fptr);
    }
    fclose(fptr);
    return counter;
}

void Put_file_characteristics_to_structure(TheInputFile* input_file)
{
    input_file->input_file_name = "textInput.txt";
    input_file->file_size = num_of_symbols_in_file(*input_file);
    input_file->str_num = num_of_strings_in_file(*input_file);
}

void Read_file_to_buffer(TheInputFile input_file, char* buffer)
{
    assert(buffer != NULL);
    assert(input_file.input_file_name != NULL);
    FILE* fptr = fopen(input_file.input_file_name, "r");
    if (fptr)
    {
        fread(buffer, sizeof(char), input_file.file_size, fptr);
        fclose(fptr);
    }
}

void Put_lineslen_for_all_lines(char* buffer, TheInputFile input_file, size_t* lineslen)
{
    assert(buffer != NULL);
    assert(lineslen != NULL);
    size_t num_of_the_str = 0;
    size_t count_sym_in_str = 0;
    for (size_t i = 0; i < input_file.file_size; i++)
    {
        count_sym_in_str++;
        if (buffer[i] == '\n' ||  buffer[i] == '\0' || buffer[i] == EOF)
        {
            lineslen[num_of_the_str] = count_sym_in_str - 1;
            num_of_the_str++;
            count_sym_in_str = 0;
        }
    }
}

void Put_pointers_to_lines(char* buffer, TheInputFile input_file, char** lines)
{
    assert(lines != NULL);
    assert(buffer != NULL);
    size_t num_of_the_str = 1;
    lines[0] = &buffer[0];
    for (size_t i = 1; i < input_file.file_size; i++)
    {
        if (buffer[i] == '\n')
        {
            assert(num_of_the_str <= input_file.str_num);
            lines[num_of_the_str] = &buffer[i + 1];
            num_of_the_str++;
        }
    }
}
