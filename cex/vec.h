#ifndef CEX_VEC_H
#define CEX_VEC_H

/* Standard C Library */
#include <stdlib.h>

/* CEX Library */
#include "obj.h"

/* Shorthand Macros */
#define VEC(type, len) cex_make_vec(sizeof(type), len)

/* Vector Struct */
typedef struct cex_vec {
    OBJ** elems;
    size_t esz;
    size_t len;
    struct cex_vec* (*copy)(struct cex_vec*);
    void (*resz)(struct cex_vec*, size_t);
    void (*free)(struct cex_vec*);
} VEC;

/* Vector Methods */
VEC* cex_make_vec(size_t esz, size_t len);
VEC* cex_copy_vec(VEC* V);
void cex_resz_vec(VEC* V, size_t len);
void cex_free_vec(VEC* V);

#endif // CEX_VEC_H
