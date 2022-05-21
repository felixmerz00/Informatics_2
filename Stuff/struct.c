#include <stdio.h>

struct rec{ int a; int b; };

int main()
{
    struct rec r;
    r.a = 5; r.b = 8;
    printf("Sum a and b is %d\n", r.a + r.b);

    struct rec* pr;
    (*pr).a = 6; pr->b = 9;
    printf("Sum a and b is %d\n", pr->a + pr->b);
}