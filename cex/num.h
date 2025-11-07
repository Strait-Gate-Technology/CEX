#ifndef CEX_NUM_H
#define CEX_NUM_H

/* CEX Library */
#include "obj.h"

/* Shorthand Macros */
#define NUM(i) cex_make_num(i)

/* Number */
typedef struct {
    OBJ * self;
    int * nums;
} NUM;

/* Number methods */
NUM * cex_make_num(int i);

#endif // CEX_NUM_H
