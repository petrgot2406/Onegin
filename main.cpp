#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void Swap_strings(char** string_1, char** string_2);
int strcmp(char* string_1, char* string_2);
void bubble_sort(char* text[], int n);
int num_of_symbols_in_file(const char* filename);
int num_of_strings_in_file(const char* filename);
int max_strlen_of_file(const char* filename);
void read_file_to_buffer(const char* filename, int fsize, char* buffer);
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

    int str_num = num_of_strings_in_file(input_file_name);
    int max_str_len = max_strlen_of_file(input_file_name);
    int filesize = num_of_symbols_in_file(input_file_name);

    printf("There are %d strings\n", str_num);
    printf("Max length of strings is %d\n\n", max_str_len);

    //char* buffer = (char*)calloc(max_fsize, sizeof(char));
    char* buffer = (char*)calloc(filesize + 200, sizeof(char));

    read_file_to_buffer(input_file_name, filesize, buffer);

    //fprintf(outputfile, "%s", buffer);
    printf("%s\n", buffer);

    char** strings = (char**)calloc(str_num+400, sizeof(char*));
    size_t* strlen = (size_t*)calloc(str_num, sizeof(size_t));

    int k = 0;
    int m = 0;
    for (int i = 0; i < filesize; i++)
    {
        m++;
        if (buffer[i] == '\n' ||  buffer[i] == '\0' || buffer[i] == EOF)
        {
            strlen[k] = m - 1;
            k++;
            m = 0;
        }
    }

    for (int i = 0; i < str_num; i++)
    {
        printf("%d ", strlen[i]);
    }
    printf("\n");

    printf("%d\n\n", str_num);

    strings[0] = &buffer[0];
    int j = 1;
    for (int i = 1; i < filesize; i++)
    {
        if (buffer[i] == '\n')
        {
            assert(j < str_num);
            strings[j] = &buffer[i + 1];
            j++;
        }
    }

    for (int i = 0; i < str_num; i++)
    {
        for (size_t j = 0; j < strlen[i]; j++)
        {
            printf("%c", strings[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    bubble_sort(strings, str_num);

    for (int i = 0; i < str_num; i++)
    {
        for (size_t j = 0; j < strlen[i]; j++)
        {
            printf("%c", strings[i][j]);
        }
        printf("\n");
    }
    printf("\n");


    /*
    strings[0] = &buffer[0];
    int j = 1;
    for (int i = 1; i < str_num; i++)
    {
        while (buffer[j] != '\n' && buffer[j] != '\0' && buffer[j] != EOF)
        {
            j++;
        }
        strings[i] = &buffer[j + 1];
    }
    */

    free(strlen);
    free(buffer);
    free(strings);

    /*char str[colvo1][colvo2];
    int num = 0;
    while (true)
    {
        int symbol_num = 0;
        char ch = getc(inputfile);
        while(ch != '\n' && ch != EOF && ch != '\r')
        {
            str[num][symbol_num] = ch;
            symbol_num++;
            ch = getc(inputfile);
        }
        str[num][symbol_num] = '\0';
        num++;
        if (ch == EOF)
        {
            break;
        }
    }*/

    /*int n = sizeof(str) / sizeof(str[0]);

    fprintf(outputfile, "Original Text:\n\n");
    printf("Original Text:\n\n");
    for (int i = 0; i < n; i++)
    {
        fprintf(outputfile, "%s\n", str[i]);
        printf("%s\n", str[i]);
    }*/

    /*for (int i = 0; i < colvo1; i++)
    {
        int j = 0;
        while (str[i][j] != '\n' || str[i][j] != EOF)
        {
            printf("%c", str[i][j]);
            j++;
        }
        printf("\n");
    }*/

    //const char* str[] = {};

    //char str[20][20] = {};
    /*int num = 0;
    while (true)
    {
        int symbol_num = 0;
        int ch = getc(inputfile);
        while(ch != '\n' && ch != EOF)
        {
            str[num][symbol_num] = ch;
            symbol_num++;
            ch = getc(inputfile);
        }
        num++;
        if (ch == EOF)
        {
            break;
        }
    }

    int n = sizeof(str) / sizeof(str[0]);
    fprintf(outputfile, "Original Text:\n\n");
    printf("Original Text:\n\n");
    for (int i = 0; i < n; i++)
    {
        fprintf(outputfile, "%s\n", str[i]);
        printf("%s\n", str[i]);
    } */

    /*fprintf(outputfile, "\nSorted Text:\n\n");
    printf("\nSorted Text:\n\n");
    bubble_sort(str, n);
    for (int i = 0; i < n; i++)
    {
        fprintf(outputfile, "%s\n", str[i]);
        printf("%s\n", str[i]);
    }*/

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

void bubble_sort(char* text[], int n) {
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(text[j], text[j + 1]) > 0)
            {
                Swap_strings(&text[j], &text[j + 1]);
            }
        }
    }
}

int num_of_symbols_in_file(const char* filename)
{
    assert(filename != NULL);
    FILE *fp = fopen(filename, "r");
    int counter = 0;
    while (getc(fp) != EOF)
    {
        counter++;
    }
    fclose(fp);
    return counter;
}

int num_of_strings_in_file(const char* filename)
{
    assert(filename != NULL);
    FILE *fp = fopen(filename, "r");
    int counter = 0;
    int ch = getc(fp);
    while (ch != EOF)
    {
        if (ch == '\n')
        {
            counter++;
        }
        ch = getc(fp);
    }
    fclose(fp);
    return counter;
}

int max_strlen_of_file(const char* filename)
{
    assert(filename != NULL);
    FILE *fp = fopen(filename, "r");
    int max_counter = 0;
    int counter = 0;
    int ch = getc(fp);
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
        ch = getc(fp);
    }
    fclose(fp);
    return max_counter;
}

void read_file_to_buffer(const char* filename, int fsize, char* buffer)
{
    assert(buffer != NULL);
    assert(filename != NULL);
    FILE* fptr = fopen(filename, "r");
    if (fptr)
    {
        fread(buffer, sizeof(char), fsize, fptr);
        fclose(fptr);
    }
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
