# C-Extension (CEX)

## Synopsis
C does not lack agility or implementation ideas to be better; it needs a central gathering point and a unified vision of how commonly re-coded utilities and library tools should be designed and used.

Once the pattern is established and enough usefulness accumulates in one place, it becomes more valuable than the sum of its parts to learn, follow and build off of what it offers.

## Examples
```c
#include <cex/obj.h>
#include <cex/str.h>
#include <cex/mat.h>

int main()
{
  STR * name = STR("Alex");
  STR * copy = COPY(name);

  MAT * A = MAT(ROW(1,2,3));
  MAT * B = MAT(COL(4,5,6));
  MAT * C = MUL(A,B);

  printf("Hi, your name is %s\n", name->str);
  printf("The result of A*B = %s\n", C->str);

  FREE(name);
  FREE(copy);
  FREE(A);
  FREE(B);
  FREE(C);

  return 0;
}
```

## TODO

- Create generics for ADD, SUB, MUL, DIV, such that they call corresponding ->add(), ->sub(), so on; with 2 parameters,
- Create MAT \* matrix type. Apply generics to these matrices as well.
- Creates "vectors" but like dynamic array containers for OBJ. Maybe call them VEC\* and allow pushing and popping with the generics PUSH() and POP().
- Once this is done for ->copy() and ->free(), consider string processing cases or move straight to WEB.

Think about...

1. How will WEB work? What will it represent?
2. If it does represent a webhook of sorts, how can or will responses be received? Will they all just return strings?
3. What are sane defaults for this kind of thing? Where, why and how would I find it useful to host webhooks in C?
