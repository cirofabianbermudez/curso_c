/* Description of the program
 * Author: Ciro Bermudez
 * Date: 03/06/2022
*/
#include <stdio.h>
typedef enum choices {left, left_center = 2, right_center, right = 5} choices;

int main(void){

    choices c = right_center;
    printf("%d \n", c);

    return 0;
}

