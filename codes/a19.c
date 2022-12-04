/* Description of the program
 * Author: Ciro Bermudez
*/

//#define NDEBUG
#include <assert.h>
#include <stdio.h>
#include <ctype.h>

int main(void){
    double x, y;
    while (1){
        printf("Read in 2 floats: ");
        scanf("%lf %lf", &x, &y);
        assert(y != 0);
        printf("when divided x/y = %lf\n", x/y);
    }
    return 0;
}


