#ifndef CEX_OBJ_H
#define CEX_OBJ_H

/* Standard C Library */
#include <stdlib.h>

/* Shorthand Macros */
#define OBJ(len) cex_make_obj(len)
#define COPY(O) O->copy(O)
#define RESIZE(O, len) O->resize(O, len)
#define FREE(O) O->free(O)

/* Object Struct */
typedef struct cex_obj {
    void* dat;
    size_t len;
    struct cex_obj* (*copy)(struct cex_obj*);
    void (*resize)(struct cex_obj*, size_t);
    void (*free)(struct cex_obj*);
} OBJ;

/* Object methods */
OBJ* cex_make_obj(size_t len);
OBJ* cex_copy_obj(OBJ* O);
void cex_resize_obj(OBJ* O, size_t len);
void cex_free_obj(OBJ* O);

#endif // CEX_OBJ_H
