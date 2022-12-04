/* Description of the program
 * Author: Ciro Bermudez
 * Date: 03/06/2022
*/
#include <stdio.h>
#define SIZE 8

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

void mergesort(int how_many, int key[]){
    int j, k;
    int w[how_many];

    for(k = 1; k < how_many; k *= 2){
        for(j = 0; j < how_many - k; j += 2*k)
            merge(k, key + j, key + j + k, w + j);
        for( j = 0; j < how_many; j++)
            key[j] = w[j];
        print_array(how_many, w, "\n\niteration\n");
    }
            
}

int main(void){
    int a[SIZE] = {99, 82, 74, 85, 92, 67, 76, 49};
    print_array(SIZE, a, "My grades\n");
    printf("\n\n");
    mergesort(SIZE, a);
    print_array(SIZE, a, "My sorted grades\n");
    printf("\n\n");

    return 0;
}

