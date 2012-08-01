#include <stdio.h>
#include <stdlib.h>


int
fibonacci (int number) {
    return ( number < 2 )
        ? number
        : fibonacci(number-1) + fibonacci(number-2);
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
