#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Struct.h"
#include "Input.h"

size_t num_of_symbols_in_file(TextOrig original_text)
{
    assert(original_text.input_file_name != NULL);

    FILE *fptr = fopen(original_text.input_file_name, "r");
    size_t counter = 0;
    while (getc(fptr) != EOF)
    {
        counter++;
    }
    fclose(fptr);
    return counter;
}

size_t num_of_strings_in_file(TextOrig original_text)
{
    assert(original_text.input_file_name != NULL);

    FILE *fptr = fopen(original_text.input_file_name, "r");
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

void Put_file_characteristics_to_structure(TextOrig* original_text)
{
    original_text->input_file_name = "textInput.txt";
    original_text->file_size = num_of_symbols_in_file(*original_text);
    original_text->str_num = num_of_strings_in_file(*original_text);
}

void Read_file_to_buffer(TextOrig* original_text)
{
    assert(original_text->input_file_name != NULL);

    original_text->buffer = (char*)calloc(original_text->file_size, sizeof(char));

    FILE* fptr = fopen(original_text->input_file_name, "r");
    if (fptr)
    {
        fread(original_text->buffer, sizeof(char), original_text->file_size, fptr);
        fclose(fptr);
    }
}

void Put_lineslen_for_all_lines(TextOrig original_text, TextSort* sorted_text)
{
    assert(original_text.buffer != NULL);

    sorted_text->lineslen = (size_t*)calloc(original_text.str_num, sizeof(size_t));

    size_t num_of_the_str = 0;
    size_t count_sym_in_str = 0;
    for (size_t i = 0; i < original_text.file_size; i++)
    {
        count_sym_in_str++;
        if (original_text.buffer[i] == '\n' ||
            original_text.buffer[i] == '\0' ||
            original_text.buffer[i] == EOF)
        {
            sorted_text->lineslen[num_of_the_str] = count_sym_in_str - 1;
            num_of_the_str++;
            count_sym_in_str = 0;
        }
    }
}

void Put_pointers_to_lines(TextOrig original_text, TextSort* sorted_text)
{
    assert(original_text.buffer != NULL);

    sorted_text->lines = (char**)calloc(original_text.str_num + 1, sizeof(char*));

    size_t num_of_the_str = 1;
    sorted_text->lines[0] = &original_text.buffer[0];
    for (size_t i = 1; i < original_text.file_size; i++)
    {
        if (original_text.buffer[i] == '\n')
        {
            assert(num_of_the_str <= original_text.str_num);

            sorted_text->lines[num_of_the_str] = &original_text.buffer[i + 1];
            num_of_the_str++;
        }
    }
}

void Put_inputfile_to_structure(Text* the_text)
{
    Put_file_characteristics_to_structure(&the_text->original_text);
    Read_file_to_buffer(&the_text->original_text);
    Put_lineslen_for_all_lines(the_text->original_text, &the_text->sorted_text);
    Put_pointers_to_lines(the_text->original_text, &the_text->sorted_text);
}
