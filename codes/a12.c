/* Description of the program
 * Author: Ciro Bermudez
 * Date: 03/06/2022
*/
#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int how_many, int data[], char *str){
    int i;
    printf("%s", str);

    for(i = 0; i < how_many; i++){
        printf("%d\t", data[i] );
    }
    printf("\n");
}

void bubble(int how_many, int data[] ){
    int i, j, wait, stop;
    for(j = 0; j < how_many - 1; j++){
        print_array(how_many, data, " \n\ninside bubble\n");
        printf("j = %d, Press any int to continue: ", j);
        scanf("%d", &wait);
        stop = 0;
        for(i = how_many - 1; i > j; i--){
            if( data[i-1] > data[i] ){
                swap( &data[i-1], &data[i] );
                stop = 1;
            }
            printf("\ni = %d\n", i);
            print_array(how_many, data, "");
        }
        if(!stop)
            break;
    }
}

int main(void){
    
    int data[] = {2, 1, 3, 4, 5};
    print_array(5, data, "\nUNSORTED\n");
    bubble(5, data);
    print_array(5, data, "\nSORTED\n");

    return 0;
}

