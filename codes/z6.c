/* Description of the program
 * Author: Ciro Bermudez
 * Date: 03/06/2022
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int array[], int length);
void swap(int *x, int *y);
int  partition(int array[], int low, int high);
void quicksort_recursion(int array[], int low, int high);
void quicksort(int array[], int length);

int main(void){
    int a[] = {6, 3, 7, 5, 1, 2, 4};
    int length = 7;

    printf("Unsorted array:\n");
    print_array(a, 7);
    quicksort(a, length);
    printf("Sorted array:\n");
    print_array(a, 7);


    return 0;
}


void print_array(int array[], int length){
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void swap(int *x, int *y){
    int temp = *x;
    *x =  *y;
    *y = temp;
}

int partition(int array[], int low, int high){
    int pivot_index = low + (rand() % (high - low + 1));

    if (pivot_index != high) {
        swap(&array[pivot_index], &array[high]);
    }
  
    int pivot_value = array[high];
    int i = low; 
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot_value) {
            swap(&array[i], &array[j]);
            i++;
        }
    }
    swap(&array[i], &array[high]);
    return i;
}

void quicksort_recursion(int array[], int low, int high){
    if (low < high) {
        int pivot_index = partition(array, low, high);
        quicksort_recursion(array, low, pivot_index - 1);
        quicksort_recursion(array, pivot_index + 1, high);
    }
}

void quicksort(int array[], int length){
    srand(time(NULL));
    quicksort_recursion(array, 0, length - 1);
}

