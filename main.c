#include <stdio.h>
#include <stdlib.h>

#include "cex/num.h"
#include "cex/obj.h"
#include "cex/str.h"
#include "cex/vec.h"

int main()
{
    int i;

    STR* name = STR("Alex");
    STR* copy = COPY(name);
    NUM* age = NUM(24);
    NUM* inc = NUM(1);
    VEC* vals = VEC(int, 5);

    printf("Hello %s\n", name->str);
    printf("The copy of your name is %s\n", copy->str);
    printf("The value of your age is %d\n", age->nums[0]);

    for (i = 0; i < 5; i++) {
        ADD(age, inc);
        printf("ADD(age, inc), age = %d\n", age->nums[0]);
    }

    for(i = 0; i < vals->len; i++) {
        *((int*)vals->elems[i]->dat) = i;
    }

    for(i = 0; i < vals->len; i++) {
        printf("vals->elems[%d] = %d\n", i, *((int*)vals->elems[i]->dat));
    }

    FREE(name);
    FREE(copy);
    FREE(age);
    FREE(inc);
    FREE(vals);

    return 0;
}
