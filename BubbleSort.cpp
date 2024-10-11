#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Struct.h"
#include "BubbleSort.h"

void Swap_size_t(size_t* n1, size_t* n2)
{
    size_t temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void Swap_lines(char** string_1, char** string_2)
{
    char* temp = *string_1;
    *string_1 = *string_2;
    *string_2 = temp;
}

bool IsLetter(char the_symbol)
{
    if ((the_symbol >= 'a' && the_symbol <= 'z') || (the_symbol >= 'A' && the_symbol <= 'Z'))
    {
        return true;
    }
    return false;
}

size_t length_of_the_string(char* the_string)
{
    size_t counter = 0;
    while (the_string[counter] != '\0' && the_string[counter] != '\n' && the_string[counter] != EOF)
    {
        counter++;
    }
    return counter;
}

int strcmp(char* string_1, char* string_2)
{
    assert(string_1 != NULL && string_2 != NULL);

    int number_of_symbol_1 = 0;
    int number_of_symbol_2 = 0;
    while (string_1[number_of_symbol_1] != '\0' || string_2[number_of_symbol_2] != '\0')
    {
        while (not(IsLetter(string_1[number_of_symbol_1])) || not(IsLetter(string_2[number_of_symbol_2])))
        {
            if (not(IsLetter(string_1[number_of_symbol_1])))
            {
                number_of_symbol_1++;
            }
            if (not(IsLetter(string_2[number_of_symbol_2])))
            {
                number_of_symbol_2++;
            }
        }
        if (string_1[number_of_symbol_1] != string_2[number_of_symbol_2])
        {
            if (string_1[number_of_symbol_1] > string_2[number_of_symbol_2])
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        number_of_symbol_1++;
        number_of_symbol_2++;
    }
    return 0;
}

int strcmp_reverse(char* string_1, char* string_2)
{
    assert(string_1 != NULL && string_2 != NULL);

    int number_of_symbol_1 = length_of_the_string(string_1);
    int number_of_symbol_2 = length_of_the_string(string_2);
    while (number_of_symbol_1 >= 0 && number_of_symbol_2 >= 0)
    {
        while (not(IsLetter(string_1[number_of_symbol_1])) || not(IsLetter(string_2[number_of_symbol_2])))
        {
            if (not(IsLetter(string_1[number_of_symbol_1])))
            {
                number_of_symbol_1--;
            }
            if (not(IsLetter(string_2[number_of_symbol_2])))
            {
                number_of_symbol_2--;
            }
        }
        if (string_1[number_of_symbol_1] != string_2[number_of_symbol_2])
        {
            if (string_1[number_of_symbol_1] > string_2[number_of_symbol_2])
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        number_of_symbol_1--;
        number_of_symbol_2--;
    }
    return 0;
}

void Bubble_sort(Text* the_text)
{
    assert(&the_text->original_text.input_file_name != NULL);
    assert(&the_text->sorted_text.lines != NULL);

    for (size_t i = 0; i < the_text->original_text.str_num - 1; i++)
    {
        for (size_t j = 0; j < the_text->original_text.str_num - i - 1; j++)
        {
            if (strcmp(the_text->sorted_text.lines[j], the_text->sorted_text.lines[j + 1]) > 0)
            {
                Swap_lines(&the_text->sorted_text.lines[j], &the_text->sorted_text.lines[j + 1]);
                Swap_size_t(&the_text->sorted_text.lineslen[j], &the_text->sorted_text.lineslen[j + 1]);
            }
        }
    }
}

void Bubble_sort_reverse(Text* the_text)
{
    assert(&the_text->original_text.input_file_name != NULL);
    assert(&the_text->sorted_text.lines != NULL);

    for (size_t i = 0; i < the_text->original_text.str_num - 1; i++)
    {
        for (size_t j = 0; j < the_text->original_text.str_num - i - 1; j++)
        {
            if (strcmp_reverse(the_text->sorted_text.lines[j], the_text->sorted_text.lines[j + 1]) > 0)
            {
                Swap_lines(&the_text->sorted_text.lines[j], &the_text->sorted_text.lines[j + 1]);
                Swap_size_t(&the_text->sorted_text.lineslen[j], &the_text->sorted_text.lineslen[j + 1]);
            }
        }
    }
}

