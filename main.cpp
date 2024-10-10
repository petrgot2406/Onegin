#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Input.h"
#include "BubbleSort.h"
#include "Output.h"

int main()
{
    const char* output_file_name = "textOutput.txt";
    FILE* output_file = fopen(output_file_name, "w");

    struct TheInputFile input_file = {};

    Put_file_characteristics_to_structure(&input_file);

    char* buffer = (char*)calloc(input_file.file_size, sizeof(char));
    char** lines = (char**)calloc(input_file.str_num + 1, sizeof(char*));
    size_t* lineslen = (size_t*)calloc(input_file.str_num, sizeof(size_t));

    Read_file_to_buffer(input_file, buffer);
    Put_pointers_to_lines(buffer, input_file, lines);
    Put_lineslen_for_all_lines(buffer, input_file, lineslen);

    fprintf(output_file, "Original text:\n\n");
    Print_lines(lines, lineslen, input_file, output_file);

    Bubble_sort(lines, lineslen, input_file);

    fprintf(output_file, "Sorted text 1:\n\n");
    Print_lines(lines, lineslen, input_file, output_file);

    Bubble_sort_reverse(lines, lineslen, input_file);

    fprintf(output_file, "Sorted text 2:\n\n");
    Print_lines(lines, lineslen, input_file, output_file);

    fclose(output_file);

    free(buffer);
    free(lines);
    free(lineslen);

    return 0;
}
