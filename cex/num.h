#ifndef CEX_NUM_H
#define CEX_NUM_H

/* CEX Library */
#include "obj.h"

/* Shorthand Macros */
#define NUM(i) cex_make_num(i)
#define ADD(A, B) A->add(A, B)

/* Number */
typedef struct cex_num {
    OBJ* self;
    int* nums;
    size_t len;
    void (*add)(struct cex_num*, struct cex_num*);
    struct cex_num* (*copy)(struct cex_num*);
    void (*resz)(struct cex_num*, size_t);
    void (*free)(struct cex_num*);
} NUM;

/* Number methods */
NUM* cex_make_num(int i);
NUM* cex_copy_num(NUM* N);
void cex_resz_num(NUM* N, size_t len);
void cex_free_num(NUM* N);

/* Arithmetic */
void cex_add_nums(NUM* A, NUM* B);

#endif // CEX_NUM_H
