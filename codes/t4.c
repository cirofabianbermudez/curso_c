/* Use of the math library
 * Author: Ciro Bermudez
 * Compile: gcc -o output.exe t4.c -lm
*/
#include <stdio.h>
#include <math.h> /* has sin(), abs(), and fabs()*/

int main(void){
    double interval;
    int i;
    for(i = 0; i < 30; i++){
        interval = i/10.0;
        printf(" | sin( %4.2lf ) | = %lf\n", interval, fabs( sin(interval) ) );
    }

    printf("\n+++++++\n");
    return 0;
}

