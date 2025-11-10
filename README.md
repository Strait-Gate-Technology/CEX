# C-Extended (CEX)

## Synopsis
C does not lack agility or implementation ideas to be better; it needs a central gathering point and a unified vision of how commonly re-coded utilities and library tools should be designed and used.

Once the pattern is established and enough usefulness accumulates in one place, it becomes more valuable than the sum of its parts to learn, follow and build off of what it offers.

## Examples

### Strings

```c
#include <cex/str.h>

int main()
{
  STR * name = STR("Alex");
  STR * copy = COPY(name);

  printf("Hi, your name is %s\n", name->str);
  printf("The copy of your name is %s\n", copy->str);

  FREE(name);
  FREE(copy);

  return 0;
}
```

### Matrices

```c
#include <cex/str.h>
#include <cex/mat.h>

int main()
{
  MAT * A = MAT(ROW(1,2,3));
  MAT * B = MAT(COL(4,5,6));
  MAT * C = MUL(A,B);

  printf("The result of A*B = %s\n", C->str);

  FREE(A);
  FREE(B);
  FREE(C);

  return 0;
}
```

## How does it work?

The `OBJ*` struct makes all of this possible by providing a generic wrapper or container for `void*` type data of `size_t` length.

```c
#include <cex/obj.h>

int main()
{
  OBJ* my_obj = OBJ(1024); /* bytes */
  ...
  FREE(my_obj); /* frees dat and OBJ */
}
```

Familiar dynamic memory operations such as `free()` and `realloc()` are given generic equivalents whose effects apply to the contents of the `OBJ*`.

```c
#define FREE(O) O->free(O)
...
void cex_free_obj(OBJ* O)
{
    free(O->dat);
    free(O);
}
```

Which are invoked using the `FREE()` shorthand macro...

```c
{
  FREE(my_obj);
}
```

...which is a member method of `OBJ*`.

```c
#define FREE(O) O->free(O)
```

From there, `OBJ*` derivatives like `STR*` can include `OBJ*` contents and functionality while providing type-specific features and representations for the underlying data.

```c
#include <cex/str.h>
...
{
  STR * version = STR("v0.1.0");
  ...
  FREE(version);
}
```

This is very much like what a lot of object models propose without being utter garbage.

## TODO

- Consider how types like NUM() can be visually displayed or stringified such that debugging or size-stepping their value easily is possible. Ideas like NUM->val or NUM->str are good.
- Creates "vectors" but like dynamic array containers for OBJ. Maybe call them VEC\* and allow pushing and popping with the generics PUSH() and POP().
- Try and compile (convert) the project to be C89 compliant...may not be possible with certain design goals in mind.
- Create remaining generics for NUM (i.e. SUB(), MUL(), etc.) after ADD() is now here.
- Create MAT \* matrix type. Apply generics to these matrices as well.
- Once this is done for ->copy() and ->free(), consider string processing cases or move straight to WEB.

Think about...

1. How will WEB work? What will it represent?
2. If it does represent a webhook of sorts, how can or will responses be received? Will they all just return strings?
3. What are sane defaults for this kind of thing? Where, why and how would I find it useful to host webhooks in C?
