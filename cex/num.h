#ifndef CEX_NUM_H
#define CEX_NUM_H

/* CEX Library */
#include "obj.h"

/* Shorthand Macros */
#define NUM(i) cex_make_num(i)

/* Number */
typedef struct cex_num {
    OBJ* self;
    int* nums;
    size_t len;
    struct cex_num* (*copy)(struct cex_num*);
    void (*free)(struct cex_num*);
} NUM;

/* Number methods */
NUM* cex_make_num(int i);
NUM* cex_copy_num(NUM* N);
void cex_free_num(NUM* N);

#endif // CEX_NUM_H
