#include "cex/num.h"

/* Standard C Library */
#include <stdlib.h>
#include <string.h>

NUM* cex_make_num(unsigned int i)
{
    NUM* new_num;
    new_num = malloc(sizeof(NUM));
    new_num->self = OBJ(sizeof(unsigned int));
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
    RESZ(N->self, len * sizeof(unsigned int));
    N->len = len;
}

void cex_free_num(NUM* N)
{
    FREE(N->self);
    free(N);
}

void cex_add_nums(NUM* A, NUM* B)
{
    unsigned int i, sum, carry;
    unsigned int high_bit_A, high_bit_B, high_bit_sum;

    /* Sum little endian */
    carry = 0;
    for (i = 0; i < A->len && i < B->len; i++) {
        sum = A->nums[i] + B->nums[i] + carry;

        high_bit_A = (A->nums[i] >> (sizeof(int) * 8 - 1));
        high_bit_B = (B->nums[i] >> (sizeof(int) * 8 - 1));
        high_bit_sum = (sum >> (sizeof(int) * 8 - 1));

        carry = (high_bit_A | high_bit_B) & ~high_bit_sum;

        A->nums[i] = sum;
    } /* DO NOT REUSE i */
    /* Expand if necessary */
    if (A->len < (B->len + carry)) {
        RESZ(A, B->len + carry);
    }
    /* Add outstanding carry */
    /* NOTE:    it must be done this way because
                A might be HUGE but still necessitate
                a carry-add to the i'th element after
                the for-loop.*/
    if (carry) {
        A->nums[i] += carry;
    }
    /* Done */
}