/* Distance of a marathon in kilometers
 * Author: Ciro Bermudez
 * Date: 03/06/2022
*/
#include <stdio.h>

int main(void){
    int miles = 26, yards = 385;
    double kilometers;
    printf("Please enter miles as an integer: ");
    scanf("%d", &miles);
    kilometers = 1.609 * (miles + yards / 1760.0); // note the 3 conversions
    printf("A marathon is %lf kilometers.\n\n", kilometers);

    return 0;
}

