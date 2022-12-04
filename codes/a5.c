/* Print ascii
 * Author: Ciro Bermudez
 * Date: 03/06/2022
*/
#include <stdio.h>

int main(void){
    char c, i;

    for(i = 0, c = 'A'; i < 26; i++){
        if (i % 6 == 0)
            putchar('\n');
        printf("%c: %3d     ", c+i, c+i);
    }

    putchar('\n');

    for(i = 0, c = 'a'; i < 26; i++){
        if (i % 6 == 0)
            putchar('\n');
        printf("%c: %3d     ", c+i, c+i);
    }


    return 0;
}

