#ifndef CEX_STR_H
#define CEX_STR_H

/* CEX Library */
#include "obj.h"

/* Shorthand Macros */
#define STR(s) cex_make_str(s)
#define STRCPY(S) cex_copy_str(S)

/* String */
typedef struct {
    OBJ * self;
    char * str;
    size_t len;
} STR;

/* String methods */
STR * cex_make_str(char * s);
STR * cex_copy_str(STR * S);

#endif // CEX_STR_H
