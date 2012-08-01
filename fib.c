#include <stdio.h>
#include <stdlib.h>


#define POSITION(number) ((number)-2)
#define UNKNOWN (-1)


int
fibonacci (int number) {
    if ( number < 2 )
        return number;

    return calculate_fibonacci(
        number,
        (int*) malloc(number-1)
    );
}


static int
calculate_fibonacci (int number, int* cache) {
    if ( number < 2 )
        return number;

    if ( cache[POSITION(number)] == UNKNOWN )
        cache[POSITION(number)] = calculate_fibonacci(number-1, cache) + calculate_fibonacci(number-2, cache);

    return cache[POSITION(number)]
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
