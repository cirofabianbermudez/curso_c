/* Volume of a sphere
*/
#include <stdio.h>
#define PI 3.14159

int main(void){ 
    double radius = 0.0;
    printf("Enter radius: ");
    scanf("%lf", &radius);
    printf("Volume is : %lf \n\n", (4.0/3.0)*PI*radius*radius*radius);
    return 0;
}
