#include "cex/str.h"

/* Standard C Library */
#include <stdlib.h>
#include <string.h>

STR* cex_make_str(char* s)
{
    STR* new_str;
    new_str = malloc(sizeof(STR));
    new_str->self = OBJ(strlen(s) + 1);
    new_str->str = new_str->self->dat;
    strcpy(new_str->str, s);
    new_str->len = strlen(s);
    new_str->free = cex_free_str;
    return new_str;
}

STR* cex_copy_str(STR* S)
{
    STR* new_str;
    new_str = malloc(sizeof(STR));
    new_str->self = COPY(S->self);
    new_str->str = new_str->self->dat;
    new_str->len = new_str->self->len - 1;
    new_str->free = S->free;
    return new_str;
}

void cex_free_str(STR* S)
{
    FREE(S->self);
    free(S);
}