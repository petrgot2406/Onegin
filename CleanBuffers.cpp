#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Struct.h"
#include "CleanBuffers.h"

void Free_all(Text the_text)
{
    free(the_text.original_text.buffer);
    free(the_text.sorted_text.lines);
    free(the_text.sorted_text.lineslen);
}
