/* Description of the program
 * Author: Ciro Bermudez
 * Date: 03/06/2022
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int array[], int length, int a, int b){
    for (int i = 0; i < a; i++)
        printf("  ");
    printf("j\n");

    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    for (int i = 0; i < b; i++)
        printf("  ");
    printf("i\n");
}

void swap(int *x, int *y){
    int temp = *x;
    *x =  *y;
    *y = temp;
}

int partition(int array[], int low, int high){
    int pivot_index = low + (rand() % (high - low + 1));
    printf("pivot_index = %d\n", pivot_index);

    if (pivot_index != high)
        swap(&array[pivot_index], &array[high]);
  
    int pivot_value = array[high];
    int i = low; 
    printf("start:\n");
    int j = low;
    for (j = low; j < high; j++) {
        print_array(array, 7, j, i);
        if (array[j] <= pivot_value) {
            swap(&array[i], &array[j]);
            i++;
        }
    }

    print_array(array, 7, j, i);
    swap(&array[i], &array[high]);
    print_array(array, 7, j, i);
  
  return i;
}

void quicksort_recursion(int array[], int low, int high){
  // stop recursion when low >= high
  if (low < high) {
      int pivot_index = partition(array, low, high);
      quicksort_recursion(array, low, pivot_index - 1);
      printf("Left finish\n");
      quicksort_recursion(array, pivot_index + 1, high);
      printf("Right finish\n");
  }
}

void quicksort(int array[], int length){
    srand(time(NULL));
    quicksort_recursion(array, 0, length - 1);
}

int main(void){
    int a[] = {6, 3, 7, 5, 1, 2, 4};
    int length = 7;

    quicksort(a, length);
    //int i;
    //for (i = 0; i < length; i++) {
        //printf("%d ", a[i]);
    //}
    //printf("\n");

    return 0;
}
