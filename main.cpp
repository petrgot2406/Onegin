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
    const char* output_file_name = "textOutput.txt";
    FILE* output_file = fopen(output_file_name, "w");

    struct Text the_text {};

    Put_inputfile_to_structure(&the_text.original_text, &the_text.sorted_text);

    fprintf(output_file, "Original text:\n\n");
    Print_lines(the_text.original_text, the_text.sorted_text, output_file);

    Bubble_sort(the_text.original_text, &the_text.sorted_text);

    fprintf(output_file, "Sorted text 1:\n\n");
    Print_lines(the_text.original_text, the_text.sorted_text, output_file);

    Bubble_sort_reverse(the_text.original_text, &the_text.sorted_text);

    fprintf(output_file, "Sorted text 2:\n\n");
    Print_lines(the_text.original_text, the_text.sorted_text, output_file);

    fclose(output_file);

    Free_all(the_text);

    return 0;
}
