/* Create a function to print a table of sine and cosine
 * Author: Ciro Bermudez
 * Compile: gcc -o output.exe t5.c -lm
*/
#include <stdio.h>
#define  _USE_MATH_DEFINES
#include <math.h>

/* Print table of functions sine and cosine, generic values*/
void print_table();

int main(void){
    print_table();
    return 0;
}

void print_table(){
    double start = 0, end = 2.0*M_PI, step = 0.1, eval = 0.0;
    int iter = ceil( (end - start) / step );
    int i;
    printf("Parameters: start = %6.3lf, end = %6.3lf, step = %6.3lf, iter = %d\n\n", start, end, step, iter);
    for(i = 0; i < iter; i++ ){
        eval = start + step*i;
        printf(" sin( %6.3lf ) = %6.3lf, cos( %6.3lf ) = %6.3lf\n", eval, sin(eval), eval, cos(eval) );
    }
}
