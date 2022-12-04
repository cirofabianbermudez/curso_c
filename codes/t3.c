/* Evaluate sine function
 * Author: Ciro Bermudez
 * Compile: gcc -o out.exe t3.c -lm
*/
#include <stdio.h>
#include <math.h>

int main(void){
    double argument = 0.0;
    printf("Enter a number between 0 and 1: ");
    scanf("%lf", &argument);
    printf("sin(%lf) = %lf\n", argument, sin(argument) );

    return 0;
}
