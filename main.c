#include <stdio.h>
#include <stdlib.h>

#include "cex/num.h"
#include "cex/obj.h"
#include "cex/str.h"

int main()
{
    int i;

    STR* name = STR("Alex");
    STR* copy = COPY(name);
    NUM* age = NUM(24);
    NUM* inc = NUM(1);

    printf("Hello %s\n", name->str);
    printf("The copy of your name is %s\n", copy->str);
    printf("The value of your age is %d\n", age->nums[0]);

    for (i = 0; i < 5; i++) {
        ADD(age, inc);
        printf("ADD(age, inc), age = %d\n", age->nums[0]);
    }

    FREE(name);
    FREE(copy);
    FREE(age);

    return 0;
}
