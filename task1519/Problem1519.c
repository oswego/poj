#include <stdio.h>

int main() {

    char    d;
    int     sum;
    int     root;

    while ( ( d = getchar() ) != '0' ) {
    
        sum = d - '0';
        while ( ( d = getchar() ) != '\n' )
            sum += d - '0';

        printf("%d\n", ( root = sum % 9 ) ? root : 9);
    }

    return 0;
}