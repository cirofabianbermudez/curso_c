/* Compute area of a circle
 * Author: Ciro Bermudez
 * Date: 04/06/2022
*/
#include <stdio.h>
#define PI 3.14159

int main(void){
    double area = 0.0, radius = 0.0; /*area in meters*/
    printf("Enter radius: ");
    scanf("%lf", &radius);
    area = PI * radius * radius; // classic formula
    printf("Radius of %lf meters\nArea is %lf sq. meters\n", radius, area);
    return 0;
}

