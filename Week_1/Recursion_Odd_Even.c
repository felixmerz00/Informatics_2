#include <stdio.h>

int even(int n);
int even2(int n);

/*Odd2 and even2 are based on the given solution from slide 65/82, p.148 from the slide deck.*/
int odd2(int n)
{
    return n > 0 && even2(n-1);
}

int even2(int n)
{
    return (n == 0 || odd2(n-1));
}

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
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    /*uncomment this section if you want to use even(), odd() instead of even2(), odd2()
    int is_even, is_odd;
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
    }*/


    //odd2 and even2 are based on the given solution from slide 65/82, p.148 from the slide deck.
    if(even2(n)){
        printf("The number %d is even.\n", n);
    }
    else if(odd2(n)){
        printf("The number %d is odd.\n", n);
    }
    else{
        printf("The number %d is invalid\n", n);
    }

    return 0;
}