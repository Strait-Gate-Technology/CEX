#include "cex/obj.h"

/* Standard C Library */
#include <stdlib.h>
#include <string.h>

OBJ* cex_make_obj(size_t len)
{
    OBJ* new_obj;
    new_obj = malloc(sizeof(OBJ));
    new_obj->dat = malloc(len);
    new_obj->len = len;
    new_obj->copy = cex_copy_obj;
    new_obj->free = cex_free_obj;
    return new_obj;
}

OBJ* cex_copy_obj(OBJ* O)
{
    OBJ* new_obj;
    new_obj = OBJ(O->len);
    memcpy(new_obj->dat, O->dat, O->len);
    new_obj->copy = O->copy;
    new_obj->free = O->free;
    return new_obj;
}

void cex_resz_obj(OBJ* O, size_t len)
{
    O->dat = realloc(O->dat, len);
    O->len = len;
}

void cex_free_obj(OBJ* O)
{
    free(O->dat);
    free(O);
}
