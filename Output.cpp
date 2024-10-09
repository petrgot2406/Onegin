#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Input.h"
#include "Output.h"

void Print_strings(char** strings, size_t* strlen, TheInputFile input_file)
{
    for (size_t i = 0; i < input_file.str_num; i++)
    {
        for (size_t j = 0; j < strlen[i]; j++)
        {
            printf("%c", strings[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
