#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Struct.h"
#include "Output.h"

void Print_lines(Text the_text, FILE* output_file)
{
    assert(the_text.sorted_text.lines != NULL);
    assert(the_text.sorted_text.lineslen != NULL);
    assert(the_text.original_text.input_file_name != NULL);
    assert(output_file != NULL);

    for (size_t i = 0; i < the_text.original_text.str_num; i++)
    {
        for (size_t j = 0; j < the_text.sorted_text.lineslen[i]; j++)
        {
            fprintf(output_file, "%c", the_text.sorted_text.lines[i][j]);
        }
        fprintf(output_file, "\n");
    }
    fprintf(output_file, "\n");
}
