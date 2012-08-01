#include <stdio.h>
#include <stdlib.h>


int
main (int argc, char *argv[]) {
    if ( argc != 2 ) {
        printf("Usage: fib <integer positive number>");
        return 1;
    }

    printf("0");

    return 0;
}
