#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Input.h"
#include "Output.h"

void Print_lines(char** lines, size_t* lineslen, TheInputFile input_file, FILE* output_file)
{
    assert(lines != NULL && lineslen != NULL);
    assert(input_file.input_file_name != NULL && output_file != NULL);
    for (size_t i = 0; i < input_file.str_num; i++)
    {
        for (size_t j = 0; j < lineslen[i]; j++)
        {
            fprintf(output_file, "%c", lines[i][j]);
        }
        fprintf(output_file, "\n");
    }
    fprintf(output_file, "\n");
}
