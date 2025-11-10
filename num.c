#include "cex/num.h"

/* Standard C Library */
#include <stdlib.h>
#include <string.h>

NUM* cex_make_num(int i)
{
    NUM* new_num;
    new_num = malloc(sizeof(NUM));
    new_num->self = OBJ(sizeof(int));
    new_num->nums = new_num->self->dat;
    new_num->nums[0] = i;
    new_num->len = 1;
    new_num->add = cex_add_nums;
    new_num->copy = cex_copy_num;
    new_num->resz = cex_resz_num;
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
    new_num->add = N->add;
    new_num->copy = N->copy;
    new_num->resz = N->resz;
    new_num->free = N->free;
    return new_num;
}

void cex_resz_num(NUM* N, size_t len)
{
    RESZ(N->self, len * sizeof(int));
    N->len = len;
}

void cex_free_num(NUM* N)
{
    FREE(N->self);
    free(N);
}

/* Little endian */
void cex_add_nums(NUM* A, NUM* B)
{
    int i, aWasPos, bWasPos;

    aWasPos = (A->nums[0] >= 0);
    bWasPos = (B->nums[0] >= 0);
    for (i = 0; i < A->len && i < B->len; A->nums[i] += B->nums[i], i++) {
        aWasPos = (A->nums[i] >= 0);
        bWasPos = (B->nums[i] >= 0);
    }
}