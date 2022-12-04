/* Count number of letters, digits, letters, others
 * Author: Ciro Bermudez
 * Date: 03/06/2022
*/
#include <stdio.h>

int main(void){
    int blanks = 0, digits = 0, letters = 0, others = 0, newlines = 0, total_chars = 0;
    int c;

    while ( ( c = getchar() ) != EOF ){
        ++total_chars;
        if ( c == ' ' )
            ++blanks;
        else if ( c >= '0' && c <= '9' )
            ++digits;
        else if ( c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' )
            ++letters;
        else if ( c == '\n')
            ++newlines;
        else
            ++others;
    }

    printf(" blanks = %d, digits = %d, letters = %d, others = %d, newlines = %d, total_chars = %d\n",blanks, digits, letters, others, newlines, total_chars);

    return 0;
}

