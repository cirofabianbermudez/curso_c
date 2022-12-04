/* Conversion of Fahrenheit to Celsius
 * C = (F - 32)/1.8
 * Author: Ciro Bermudez
 * Date: 03/06/2022
*/
#include <stdio.h>

int main(void){

    int fahrenheit, celsius;
    printf("Please enter fahrenheit as an integer: ");
    scanf("%d", &fahrenheit);
    celsius = (fahrenheit - 32)/1.8; // note both conversion
    printf("%d fahrenheit is %d celsius.\n",fahrenheit, celsius);

    return 0;
}

