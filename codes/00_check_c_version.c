/* Check the version of C, we have C18
 * Author: Ciro Bermudez
 * Date: 04/06/2022
*/
#include <stdio.h>

int main(void){
    printf("__STDC_VERSION__ = %lld\n",__STDC_VERSION__);
    printf("C18: __STDC_VERSION__ = 201710L ISO/IEC 9899:2018\n");
    return 0;
}

