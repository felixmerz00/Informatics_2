#include <stdio.h>

int even(int n);

int odd(int n)
{
    if(n == 0){
        return -1;
    }
    else{
        return even(n-1);
    }
}

int even(int n)
{
    if(n == 0){
        return 1;
    }
    else{
        return odd(n-1);
    }
}

int main()
{
    int n, is_even, is_odd;
    printf("Enter a number: ");
    scanf("%d", &n);
    if(n < 0){
        printf("The number must be greater or equal to zero.\n");
        return 0;
    }
    is_even = even(n);
    is_odd = odd(n);
    if(is_even == 1 && is_odd == -1){
        printf("The number %d is even.\n", n);
    }
    else{
        printf("The number %d is odd.\n", n);
    }
    return 0;
}