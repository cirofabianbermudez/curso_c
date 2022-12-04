/* Description of the program
 * Author: Ciro Bermudez
*/
#include <stdio.h>

long fibonacci(int n){
    long f2 = 0, f1 = 1; f_old;
    int i;
    for(i = 0; i < n; i++){
        fold = f2;
        f2 = f1 + f2;
        f1 = fold;
    }
    return f2;
}

long recursive_fibonacci(int n){
    if(n <= 1)
        return n;
    else
        return ( recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2) );
}

int main(void){



    return 0;
}

