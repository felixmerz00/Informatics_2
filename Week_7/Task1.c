#include <stdio.h>
#include <stdlib.h>

int main()
{
    double d;
    int i;
    char ch = 'g';
    double* p_d;
    int* p_i;
    char* p_ch;

    //print their values
    printf("Values from d: %f, i: %d, ch: %c, p_d: %p, p_i: %p, p_ch: %p\n", d, i, ch, p_d, p_i, p_ch);
    //print their addresses
    printf("Adresses from d: %p, i: %p, ch: %p, p_d: %p, p_i: %p, p_ch: %p\n", &d, &i, &ch, &p_d, &p_i, &p_ch);
    //print their memory size
    printf("Memory size of d: %lu, i: %lu, ch: %lu, p_d: %lu, p_i: %lu, p_ch: %lu\n", sizeof(d), sizeof(i), sizeof(ch), sizeof(p_d), sizeof(p_i), sizeof(p_ch));

    return 0;
}