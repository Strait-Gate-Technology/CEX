#include "cex/num.h"

/* Standard C Library */
#include <stdlib.h>
#include <string.h>

NUM* cex_make_num(int i)
{
    NUM* new_num;
    new_num = malloc(sizeof(NUM));
    new_num->self = OBJ(sizeof(i));
    new_num->nums = new_num->self->dat;
    new_num->nums[0] = i;
    new_num->len = 1;
    new_num->free = cex_free_num;
    return new_num;
}

NUM* cex_copy_num(NUM* N)
{
    NUM* new_num;
    new_num = malloc(sizeof(NUM));
    new_num->self = COPY(N->self);
    new_num->nums = new_num->self->dat;
    new_num->len = N->len;
    new_num->free = N->free;
    return new_num;
}

void cex_free_num(NUM* N)
{
    FREE(N->self);
    free(N);
}