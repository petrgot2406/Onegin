#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Input.h"
#include "Output.h"

void Print_lines(char** lines, size_t* lineslen, TheInputFile input_file)
{
    const char* output_file_name = "oneginoutput.txt";
    FILE* output_file = fopen(output_file_name, "w");

    for (size_t i = 0; i < input_file.str_num; i++)
    {
        for (size_t j = 0; j < lineslen[i]; j++)
        {
            fprintf(output_file, "%c", lines[i][j]);
            printf("%c", lines[i][j]);
        }
        fprintf(output_file, "\n");
        printf("\n");
    }
    fprintf(output_file, "\n");
    printf("\n");
    fclose(output_file);
}
