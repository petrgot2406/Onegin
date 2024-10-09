#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void Swap_strings(char** string_1, char** string_2);
int strcmp(char* string_1, char* string_2);
void bubble_sort(char** strings, size_t str_num);
size_t num_of_symbols_in_file(const char* filename);
size_t num_of_strings_in_file(const char* filename);
size_t max_strlen_of_file(const char* filename);
void read_file_to_buffer(const char* filename, size_t filesize, char* buffer);
void put_strlen_for_all_strings(char* buffer, size_t filesize, size_t* strlen);
void put_pointers_to_strings(char* buffer, size_t filesize, size_t str_num, char** strings);
void print_strings(char** strings, size_t* strlen, size_t str_num);
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

    const char* input_file_name = "onegin.txt";
    //FILE* outputfile = fopen("oneginoutput.txt", "w");
    //FILE* inputfile = fopen("onegin.txt", "r");

    size_t str_num = num_of_strings_in_file(input_file_name);
    size_t max_str_len = max_strlen_of_file(input_file_name);
    size_t filesize = num_of_symbols_in_file(input_file_name);

    //size_t max_fsize = str_num * max_str_len;
    //char* buffer = (char*)calloc(max_fsize, sizeof(char));
    char* buffer = (char*)calloc(filesize, sizeof(char));
    char** strings = (char**)calloc(str_num + 1, sizeof(char*));
    size_t* strlen = (size_t*)calloc(str_num, sizeof(size_t));

    printf("There are %d strings\n", str_num);
    printf("Max length of strings is %d\n", max_str_len);

    read_file_to_buffer(input_file_name, filesize, buffer);

    //fprintf(outputfile, "%s", buffer);
    //printf("%s\n", buffer);

    put_strlen_for_all_strings(buffer, filesize, strlen);

    for (size_t i = 0; i < str_num; i++)
    {
        printf("%d ", strlen[i]);
    }
    printf("\n");

    put_pointers_to_strings(buffer, filesize, str_num, strings);

    printf("Original text:\n");
    print_strings(strings, strlen, str_num);

    bubble_sort(strings, str_num);

    printf("Sorted text:\n");
    print_strings(strings, strlen, str_num);

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

void bubble_sort(char** strings, size_t str_num) {
    for (size_t i = 0; i < str_num - 1; i++)
    {
        for (size_t j = 0; j < str_num - i - 1; j++)
        {
            if (strcmp(strings[j], strings[j + 1]) > 0)
            {
                Swap_strings(&strings[j], &strings[j + 1]);
            }
        }
    }
}

size_t num_of_symbols_in_file(const char* filename)
{
    assert(filename != NULL);
    FILE *fptr = fopen(filename, "r");
    size_t counter = 0;
    while (getc(fptr) != EOF)
    {
        counter++;
    }
    fclose(fptr);
    return counter;
}

size_t num_of_strings_in_file(const char* filename)
{
    assert(filename != NULL);
    FILE *fptr = fopen(filename, "r");
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

size_t max_strlen_of_file(const char* filename)
{
    assert(filename != NULL);
    FILE *fptr = fopen(filename, "r");
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

void read_file_to_buffer(const char* filename, size_t filesize, char* buffer)
{
    assert(buffer != NULL);
    assert(filename != NULL);
    FILE* fptr = fopen(filename, "r");
    if (fptr)
    {
        fread(buffer, sizeof(char), filesize, fptr);
        fclose(fptr);
    }
}

void put_strlen_for_all_strings(char* buffer, size_t filesize, size_t* strlen)
{
    size_t num_of_the_str = 0;
    size_t count_sym_in_str = 0;
    for (size_t i = 0; i < filesize; i++)
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

void put_pointers_to_strings(char* buffer, size_t filesize, size_t str_num, char** strings)
{
    size_t num_of_the_str = 1;
    strings[0] = &buffer[0];
    for (size_t i = 1; i < filesize; i++)
    {
        if (buffer[i] == '\n')
        {
            assert(num_of_the_str <= str_num);
            strings[num_of_the_str] = &buffer[i + 1];
            num_of_the_str++;
        }
    }
}

void print_strings(char** strings, size_t* strlen, size_t str_num)
{
    for (size_t i = 0; i < str_num; i++)
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
