#include "cex/vec.h"

/* Standard C Library */
#include <stdlib.h>
#include <string.h>

VEC* cex_make_vec(size_t esz, size_t len)
{
    int i;
    VEC* new_vec;
    new_vec = malloc(sizeof(VEC));
    new_vec->elems = malloc(sizeof(OBJ*)*len);
    for(i = 0; i < len; i++) {
        new_vec->elems[i] = OBJ(esz);
    }
    new_vec->esz = esz;
    new_vec->len = len;
    new_vec->copy = cex_copy_vec;
    new_vec->resz = cex_resz_vec;
    new_vec->free = cex_free_vec;
    return new_vec;
}

VEC* cex_copy_vec(VEC* V)
{
    int i;
    VEC* new_vec;
    new_vec = cex_make_vec(V->esz, V->len);
    for(i = 0; i < V->len; i++) {
        new_vec->elems[i] = COPY(V->elems[i]);
    }
    new_vec->copy = V->copy;
    new_vec->resz = V->resz;
    new_vec->free = V->free;
    return new_vec;
}

void cex_resz_vec(VEC* V, size_t len)
{
    V->elems = realloc(V->elems, sizeof(OBJ*)*len);
    V->len = len;
}

void cex_free_vec(VEC* V)
{
    int i;
    for(i = 0; i < V->len; i++) {
        FREE(V->elems[i]);
    }
    free(V);
}
