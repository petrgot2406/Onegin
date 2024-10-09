#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Input.h"
#include "BubbleSort.h"

void Swap_size_t(size_t* n1, size_t* n2)
{
    size_t temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void Swap_strings(char** string_1, char** string_2)
{
    char* temp = *string_1;
    *string_1 = *string_2;
    *string_2 = temp;
}

int strcmp(char* string_1, char* string_2)
{
    int number_of_symbol = 0;
    while (string_1[number_of_symbol] != '\0' || string_2[number_of_symbol] != '\0')
    {
        if (string_1[number_of_symbol] != string_2[number_of_symbol])
        {
            if (string_1[number_of_symbol] > string_2[number_of_symbol])
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        number_of_symbol++;
    }
    return 0;
}

void Bubble_sort(char** strings, size_t* strlen, TheInputFile input_file) {
    for (size_t i = 0; i < input_file.str_num - 1; i++)
    {
        for (size_t j = 0; j < input_file.str_num - i - 1; j++)
        {
            if (strcmp(strings[j], strings[j + 1]) > 0)
            {
                Swap_strings(&strings[j], &strings[j + 1]);
                Swap_size_t(&strlen[j], &strlen[j + 1]);
            }
        }
    }
}
