#ifndef CEX_STR_H
#define CEX_STR_H

/* CEX Library */
#include "obj.h"

/* Shorthand Macros */
#define STR(s) cex_make_str(s)
#define STRCPY(S) cex_copy_str(S)

/* String */
typedef struct cex_str {
    OBJ* self;
    char* str;
    size_t len;
    void (*free)(struct cex_str*);
} STR;

/* String methods */
STR* cex_make_str(char* s);
STR* cex_copy_str(STR* S);
STR* cex_free_str(STR* S);

#endif // CEX_STR_H
