#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct TheInputFile
{
    const char* input_file_name;
    size_t file_size;
    size_t str_num;
};

void Swap_strings(char** string_1, char** string_2);
int strcmp(char* string_1, char* string_2);
void Bubble_sort(char** strings, TheInputFile input_file);
size_t num_of_symbols_in_file(TheInputFile input_file);
size_t num_of_strings_in_file(TheInputFile input_file);
size_t max_strlen_of_file(TheInputFile input_file);
void Read_file_to_buffer(TheInputFile input_file, char* buffer);
void Put_strlen_for_all_strings(char* buffer, TheInputFile input_file, size_t* strlen);
void Put_pointers_to_strings(char* buffer, TheInputFile input_file, char** strings);
void Print_strings(char** strings, size_t* strlen, TheInputFile input_file);
//void read_text_from_buffer(char* buffer, char** strings);

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
                                      num_of_strings_in_file(input_file)};

    //FILE* outputfile = fopen("oneginoutput.txt", "w");
    //FILE* inputfile = fopen("onegin.txt", "r");

    //size_t max_fsize = str_num * max_str_len;
    //char* buffer = (char*)calloc(max_fsize, sizeof(char));
    char* buffer = (char*)calloc(input_file.file_size, sizeof(char));
    char** strings = (char**)calloc(input_file.str_num + 1, sizeof(char*));
    size_t* strlen = (size_t*)calloc(input_file.str_num, sizeof(size_t));

    printf("There are %d strings\n", input_file.str_num);
    size_t max_str_len = max_strlen_of_file(input_file);
    printf("Max length of strings is %d\n", max_str_len);

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

void Bubble_sort(char** strings, TheInputFile input_file) {
    for (size_t i = 0; i < input_file.str_num - 1; i++)
    {
        for (size_t j = 0; j < input_file.str_num - i - 1; j++)
        {
            if (strcmp(strings[j], strings[j + 1]) > 0)
            {
                Swap_strings(&strings[j], &strings[j + 1]);
            }
        }
    }
}

size_t num_of_symbols_in_file(TheInputFile input_file)
{
    assert(input_file.input_file_name != NULL);
    FILE *fptr = fopen(input_file.input_file_name, "r");
    size_t counter = 0;
    while (getc(fptr) != EOF)
    {
        counter++;
    }
    fclose(fptr);
    return counter;
}

size_t num_of_strings_in_file(TheInputFile input_file)
{
    assert(input_file.input_file_name != NULL);
    FILE *fptr = fopen(input_file.input_file_name, "r");
    size_t counter = 0;
    int ch = getc(fptr);
    while (ch != EOF)
    {
        if (ch == '\n')
        {
            counter++;
        }
        ch = getc(fptr);
    }
    fclose(fptr);
    return counter;
}

size_t max_strlen_of_file(TheInputFile input_file)
{
    assert(input_file.input_file_name != NULL);
    FILE *fptr = fopen(input_file.input_file_name, "r");
    size_t max_counter = 0;
    size_t counter = 0;
    int ch = getc(fptr);
    while (ch != EOF)
    {
        counter++;
        if (ch == '\n')
        {
            if (counter > max_counter)
            {
                max_counter = counter;
            }
            counter = 0;
        }
        ch = getc(fptr);
    }
    fclose(fptr);
    return max_counter;
}

void Read_file_to_buffer(TheInputFile input_file, char* buffer)
{
    assert(buffer != NULL);
    assert(input_file.input_file_name != NULL);
    FILE* fptr = fopen(input_file.input_file_name, "r");
    if (fptr)
    {
        fread(buffer, sizeof(char), input_file.file_size, fptr);
        fclose(fptr);
    }
}

void Put_strlen_for_all_strings(char* buffer, TheInputFile input_file, size_t* strlen)
{
    size_t num_of_the_str = 0;
    size_t count_sym_in_str = 0;
    for (size_t i = 0; i < input_file.file_size; i++)
    {
        count_sym_in_str++;
        if (buffer[i] == '\n' ||  buffer[i] == '\0' || buffer[i] == EOF)
        {
            strlen[num_of_the_str] = count_sym_in_str - 1;
            num_of_the_str++;
            count_sym_in_str = 0;
        }
    }
}

void Put_pointers_to_strings(char* buffer, TheInputFile input_file, char** strings)
{
    size_t num_of_the_str = 1;
    strings[0] = &buffer[0];
    for (size_t i = 1; i < input_file.file_size; i++)
    {
        if (buffer[i] == '\n')
        {
            assert(num_of_the_str <= input_file.str_num);
            strings[num_of_the_str] = &buffer[i + 1];
            num_of_the_str++;
        }
    }
}

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

/*
void read_text_from_buffer(char* buffer, char** strings)
{
    int n = sizeof(buffer);
    int num_of_string = 0;
    int i = 0;
    while (true)
    {
        int num_of_sym = 0;
        while (*(buffer + i) != '\n')
        {
            *(strings + num_of_string) = *(buffer + i);
        }
    }
}
*/
