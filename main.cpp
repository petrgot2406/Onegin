#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Input.h"
#include "BubbleSort.h"
#include "Output.h"

int main(int argc, char* argv[])
{
    if (argc != 1)
    {
        for (int i = 1; i < argc; i++)
        {
            printf("%s\n", argv[i]);
        }
        return 1;
    }

    struct TheInputFile input_file = {"onegin.txt",
                                      num_of_symbols_in_file(input_file),
                                      num_of_strings_in_file(input_file),
                                      max_strlen_of_file(input_file)};

    //FILE* outputfile = fopen("oneginoutput.txt", "w");
    //FILE* inputfile = fopen("onegin.txt", "r");

    //size_t max_fsize = str_num * max_str_len;
    //char* buffer = (char*)calloc(max_fsize, sizeof(char));
    char* buffer = (char*)calloc(input_file.file_size, sizeof(char));
    char** strings = (char**)calloc(input_file.str_num + 1, sizeof(char*));
    size_t* strlen = (size_t*)calloc(input_file.str_num, sizeof(size_t));

    printf("There are %d strings\n", input_file.str_num);
    printf("Max length of strings is %d\n", input_file.max_str_len);

    Read_file_to_buffer(input_file, buffer);

    //fprintf(outputfile, "%s", buffer);
    //printf("%s\n", buffer);

    Put_strlen_for_all_strings(buffer, input_file, strlen);

    for (size_t i = 0; i < input_file.str_num; i++)
    {
        printf("%d ", strlen[i]);
    }
    printf("\n");

    Put_pointers_to_strings(buffer, input_file, strings);

    printf("Original text:\n");
    Print_strings(strings, strlen, input_file);

    Bubble_sort(strings, input_file);

    printf("Sorted text:\n");
    Print_strings(strings, strlen, input_file);

    free(strlen);
    free(buffer);
    free(strings);

    //fclose(inputfile);
    //fclose(outputfile);
    return 0;
}
