#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Struct.h"
#include "Input.h"
#include "BubbleSort.h"
#include "Output.h"
#include "CleanBuffers.h"

int main()
{
    struct Text the_text = {};

    Put_inputfile_to_structure(&the_text);

    const char* output_file_name = "textOutput.txt";
    FILE* output_file = fopen(output_file_name, "w");

    fprintf(output_file, "Original text:\n\n");
    Print_lines(the_text, output_file);

    Bubble_sort(&the_text);

    fprintf(output_file, "Sorted text 1:\n\n");
    Print_lines(the_text, output_file);

    Bubble_sort_reverse(&the_text);

    fprintf(output_file, "Sorted text 2:\n\n");
    Print_lines(the_text, output_file);

    fclose(output_file);

    Free_all_buffers(the_text);

    return 0;
}
