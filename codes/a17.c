/* Description of the program
 * Author: Ciro Bermudez
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int c, i, letter_upper[26] = {0}, letter_lower[26] = {0};
    FILE *ifp, *ofp;

    if (argc != 3){
        printf("\n%s%s%s\n\n%s\n%s\n\n",
                "Usage:   ", argv[0], " infile outfile",
                "The uppercase letters in the infile will be counted.",
                "The result will be written in outfile.");
        exit(1);
    }
    ifp = fopen(argv[1], "r");
    ofp = fopen(argv[2], "w");

    while ( (c = getc(ifp)) != EOF ){
        if (c >= 'A' && c <= 'Z'){
            letter_upper[c - 'A']++;
        }
        if (c >= 'a' && c <= 'z'){
            letter_lower[c - 'a']++;
        }
    }

    for (i = 0; i < 26; i++){
        if (i % 6 == 0)
            putc('\n', ofp);
        fprintf(ofp, "%c:%5d     ", 'A' + i, letter_upper[i]);
    }

    fprintf(ofp,"\n");

    for (i = 0; i < 26; i++){
        if (i % 6 == 0)
            putc('\n', ofp);
        fprintf(ofp, "%c:%5d     ", 'a' + i, letter_lower[i]);
    }


    return 0;
}

