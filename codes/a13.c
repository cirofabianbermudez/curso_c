/* Description of the program
 * Author: Ciro Bermudez
 * Date: 03/06/2022
*/
#include <stdio.h>
#define SIZE 5

void print_array(int how_many, int data[], char *str){
    int i;
    printf("%s", str);

    for(i = 0; i < how_many; i++){
        printf("%d\t", data[i] );
    }
    printf("\n");
}

void merge(int how_many, int a[], int b[], int c[] ){
    /* array is a size power of 2*/
    /* a and b same size*/
    /* i is idx for a, j is idx for b, k is idx for c */
    int i = 0, j = 0, k = 0;

    while( i < how_many && j < how_many )
        if( a[i] < b[j] )
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    while(i < how_many)
            c[k++] = a[i++];
    while(j < how_many)
            c[k++] = b[j++];

}

int main(void){
    int a[SIZE] = {67, 82, 83, 88, 99};
    int b[SIZE] = {58, 69, 73, 81, 88};
    int c[2*SIZE];
    print_array(SIZE, a, "My grades\n");
    printf("\n\n");
    print_array(SIZE, b, "More grades\n");
    printf("\n\n");
    merge(SIZE, a, b, c);
    print_array(2*SIZE, c, "Sorted grades\n");
    printf("\n\n");

    return 0;
}
