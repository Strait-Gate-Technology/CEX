#include <stdio.h>
#include <stdlib.h>

#include "cex/obj.h"
#include "cex/str.h"
#include "cex/num.h"

int main()
{
    STR * name = STR("Alex");
    STR * copy = STRCPY(name);
    NUM * age = NUM(24);

    printf("Hello %s\n", name->str);
    printf("The copy of your name is %s\n", copy->str);
    printf("The value of your age is %d\n", age->nums[0]);

    FREE(name->self);
    FREE(copy->self);
    FREE(age->self);

    free(name);
    free(copy);
    free(age);

    return 0;
}
