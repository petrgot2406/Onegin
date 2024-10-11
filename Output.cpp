#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Struct.h"
#include "Output.h"

void Print_lines(TextOrig original_text, TextSort sorted_text, FILE* output_file)
{
    assert(sorted_text.lines != NULL);
    assert(sorted_text.lineslen != NULL);
    assert(original_text.input_file_name != NULL);
    assert(output_file != NULL);

    for (size_t i = 0; i < original_text.str_num; i++)
    {
        for (size_t j = 0; j < sorted_text.lineslen[i]; j++)
        {
            fprintf(output_file, "%c", sorted_text.lines[i][j]);
        }
        fprintf(output_file, "\n");
    }
    fprintf(output_file, "\n");
}
