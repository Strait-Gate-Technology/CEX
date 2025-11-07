#ifndef CEX_STR_H
#define CEX_STR_H

/* CEX Library */
#include "obj.h"

/* Shorthand Macros */
#define STR(s) cex_make_str(s)

/* String */
typedef struct cex_str {
    OBJ* self;
    char* str;
    size_t len;
    struct cex_str* (*copy)(struct cex_str*);
    void (*free)(struct cex_str*);
} STR;

/* String methods */
STR* cex_make_str(char* s);
STR* cex_copy_str(STR* S);
void cex_free_str(STR* S);

#endif // CEX_STR_H
