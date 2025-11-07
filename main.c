#include <stdio.h>
#include <stdlib.h>

#include "cex/num.h"
#include "cex/obj.h"
#include "cex/str.h"

int main()
{
    STR* name = STR("Alex");
    STR* copy = STRCPY(name);
    NUM* age = NUM(_128bit);

    printf("Hello %s\n", name->str);
    printf("The copy of your name is %s\n", copy->str);
    printf("The value of your age is %d\n", age->nums[0]);

    FREE(name);
    FREE(copy);
    FREE(age);

    return 0;
}
