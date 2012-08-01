#include <stdio.h>
#include <stdlib.h>



#define EVEN(number) ( !(number % 2) )



static int
calculate_fibonacci (int a, int b, int p, int q, int count);


int
fibonacci (int number) {
    return ( number < 2 )
        ? number
        : calculate_fibonacci(1, 0, 0, 1, number);
}


static int
calculate_fibonacci (int a, int b, int p, int q, int count) {
    if ( !count )
        return b;
    else
        return ( EVEN(count) )
            ? calculate_fibonacci(a, b, p*p+q*q, q*(2*p+q), count/2)
            : calculate_fibonacci(q*(b+a)+a*p, b*p+a*q, p, q, count-1);
}


int
main (int argc, char *argv[]) {
    if ( argc != 2 ) {
        printf("Usage: fib <integer positive number>");
        return 1;
    }

    printf("%d\n", fibonacci(atoi(argv[1])));

    return 0;
}
