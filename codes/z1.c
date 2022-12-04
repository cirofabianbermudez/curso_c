/* Compute a better average
 * Author: Ciro Bermudez
 * Date: 03/06/2022
*/
#include <stdio.h>

int main(void){
    int i;
    double x;
    double avg = 0.0;
    double navg;
    double sum = 0.0;

    printf("%5s%17s%17s%17s\n%5s%17s%17s%17s\n\n","Count","Item","Average","Naive avg",
            "_____","____","_______","_________");
    for(i = 1; scanf("%lf", &x) == 1; ++i){
        avg += (x - avg)/i;
        sum += x;
        navg = sum/i;
        printf("%5d%17e%17e%17e\n",i,x,avg,navg);
    }

    return 0;
}

