#include <stdio.h>
#include <stdlib.h>

#include "cex/num.h"
#include "cex/obj.h"
#include "cex/str.h"

int main()
{
    /* Testing resize */
    int i, c;
    NUM* n1 = NUM(1);
    NUM* n2 = NUM(~(1u));

    printf("n1->nums[0] = %u\n", n1->nums[0]);
    printf("n1->len = %lu\n", n1->len);

    printf("n2->nums[0] = %u\n", n2->nums[0]);
    printf("n2->len = %lu\n", n2->len);

    /* Add slowly */
    while (c != 'q') {
        ADD(n2, n1);

        printf("n1->nums[0] = %u\n", n1->nums[0]);
        printf("n1->len = %lu\n", n1->len);

        printf("n2->nums[0] = %u\n", n2->nums[0]);
        printf("n2->len = %lu\n", n2->len);

        printf("Do it again? ([ENTER] to continue or 'q' to quit): ");
        c = getchar();
    }

    FREE(n1);
    FREE(n2);
}

int main_1()
{
    int i;

    STR* name = STR("Alex");
    STR* copy = COPY(name);
    NUM* age = NUM(24);
    NUM* inc = NUM((1u << (sizeof(int) * 8 - 1)) - 1);

    printf("Hello %s\n", name->str);
    printf("The copy of your name is %s\n", copy->str);
    printf("The value of your age is %d\n", age->nums[0]);

    for (i = 0; i < 5; i++) {
        ADD(age, inc);
        printf("ADD(age, inc), age = %u\n", age->nums[0]);
    }

    FREE(name);
    FREE(copy);
    FREE(age);

    return 0;
}
