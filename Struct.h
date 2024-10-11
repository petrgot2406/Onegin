#ifndef STRUCT_H
#define STRUCT_H

struct TextOrig
{
    const char* input_file_name;
    char* buffer;
    size_t str_num;
    size_t file_size;
};

struct TextSort
{
    char** lines;
    size_t* lineslen;
};

struct Text
{
    struct TextOrig original_text;
    struct TextSort sorted_text;
};

#endif
