#include "cex/num.h"

/* Standard C Library */
#include <stdlib.h>
#include <string.h>

NUM * cex_make_num(int i)
{
    NUM * new_num;
    new_num = malloc(sizeof(NUM));
    new_num->self = OBJ(sizeof(i));
    new_num->nums = new_num->self->dat;
    new_num->nums[0] = i;
    return new_num;
}
