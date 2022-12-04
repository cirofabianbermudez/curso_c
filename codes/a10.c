/* Description of the program
 * Author: Ciro Bermudez
*/
#include <stdio.h>
#define SIZE 5

int main(void){
    int data[SIZE] = {1,2,3,4,5};

    printf("%ld %ld %ld %ld \n", data, data + 1, &data[0], &data[1]);

    return 0;
}

