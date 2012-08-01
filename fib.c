#include <stdio.h>
#include <stdlib.h>


int
fibonacci (int number) {
    if ( number == 0 ) {
        return 0;
    }
    if ( number == 1 ) {
        return 1;
    }

    return fibonacci(number-1) + fibonacci(number-2);
}


int
main (int argc, char *argv[]) {
    if ( argc != 2 ) {
        printf("Usage: fib <integer positive number>");
        return 1;
    }

    printf("%d", fibonacci(atoi(number)));

    return 0;
}
