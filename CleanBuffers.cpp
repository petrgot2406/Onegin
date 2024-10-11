#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Struct.h"
#include "CleanBuffers.h"

void Free_all_buffers(Text the_text)
{
    assert(the_text.original_text.buffer != NULL);
    assert(the_text.sorted_text.lines != NULL);
    assert(the_text.sorted_text.lineslen != NULL);

    free(the_text.original_text.buffer);
    free(the_text.sorted_text.lines);
    free(the_text.sorted_text.lineslen);
}
