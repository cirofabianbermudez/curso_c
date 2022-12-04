/* Recursion
 * Author: Ciro Bermudez
 * Date: 03/06/2022
*/
#include <stdio.h>

void count(int n){
    while( n > 0 ){
        printf("time is %d\n", n);
        n--;
    }
    printf("Blast off\n");
}

void recursive_count(int n){
    if(n == 0){
        printf("Blast off\n");
    }else{
        printf("time is %d\n",n);
        recursive_count(n-1);
    }
}

int main(void){
    recursive_count(10);

    count(10);
    return 0;
}


