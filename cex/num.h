#ifndef CEX_NUM_H
#define CEX_NUM_H

/* CEX Library */
#include "obj.h"

/* Shorthand Macros */
#define NUM(i) cex_make_num(i)
#define _128bit 16 / sizeof(int)
#define _256bit 32 / sizeof(int)
#define _512bit 64 / sizeof(int)

/* Number */
typedef struct cex_num {
    OBJ* self;
    int* nums;
    void (*free)(struct cex_num*);
} NUM;

/* Number methods */
NUM* cex_make_num(size_t n);
void cex_free_num(NUM* N);

#endif // CEX_NUM_H
