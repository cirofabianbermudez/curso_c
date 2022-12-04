/* Description of the program
 * Author: Ciro Bermudez
*/
#include <stdio.h>

struct complex {
    double re;
    double im;
};

typedef struct complex complex;

int main(void){

    complex c1 = {1.1, 2.2};
    complex *ptc;

    ptc = &c1;
    //c1.re = 1.1;
    //c1.im = 2.2;
    ptc -> re = 123.0;
    ptc -> im = 456.0;

    //printf("re = %lf im = %lf\n", c1.re, c1.im);
    printf("with pointers\n");
    printf("re = %lf im = %lf\n", ptc -> re, ptc -> im);

    return 0;
}

