/* Sort 100 randomly generated intefers in a linear linked list
 * Author: Ciro Bermudez
 * Compile: gcc -o output.exe t11.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct list {
    int data;
    struct list *next;
};

typedef struct list list;

list *create_element(int value);
list *add_to_front(list *head, list *new_element);
void print_list(list **head);
int num_of_list_elem(list **head);
void swap(list *p1, list *p2);
void bubble(list *head, int size);

int main(void){
    /* Seed random number generator*/
    srand(time(NULL));
    int list_size = 100;
    int max_rand_value = 100;

    /* Random number between 1-100, fisrt element of linked list*/
    list *head = create_element( 1 + rand() % max_rand_value );
    for (int i = 0; i < list_size - 1 ; i++) {
        head = add_to_front( head, create_element( 1 + rand() % max_rand_value ) );
    }

    printf("Unsorted data\n");
    print_list(&head);

    printf("\n");
    bubble(head, list_size);

    printf("Sorted data\n");
    print_list(&head);

    return 0;
}

/* Create a single element linked list */
list *create_element(int value){
    list *head = (list *) malloc(sizeof(list));
    head -> data = value;
    head -> next = NULL;
    return head;
}

/* Add to front of the linked list and return the new head*/
list *add_to_front(list *head, list *new_element){
    new_element -> next = head;
    return new_element;
}

/* Simple print list function with pointer to pointer techniques*/
void print_list(list **head){
    list **tracer = head;
    int i = 0;
    while ((*tracer) != NULL) {
        if (i % 5 == 0 && i != 0) {
            printf("\n");
        }
        printf("%3d ", (*tracer)->data);
        tracer = &(*tracer)->next;
        i++;
    }
    printf("\n");
}

/* Count the number of elements in the linked list if necesary */
int num_of_list_elem(list **head){
    int counter = 0;
    list **tracer = head;
    while ( (*tracer) != NULL) {
        tracer = &(*tracer)->next;
        counter++;
    }
    return counter;
}

/* Swap function for two list pointers */
void swap(list *p1, list *p2){
    int temp = p1 -> data;
    (p1 -> data) = (p2 -> data);
    (p2 -> data) = temp;
}

/* Modify bubble sort for linked lists */
void bubble(list *head, int size){
    int i, j, stop;
    list *p1, *p2;

    for(j = 0; j < size - 1; j++){
        /* Point to the head of the list*/
        p1 = head;
        p2 = (head -> next);
        stop = 0;
        for(i = size - 1; i > j; i--){
            if( (p2 -> data) < (p1 -> data) ){
                swap( p2, p1 );
                stop = 1;
            }
            /* Incremenet pointer */
            /* Because of the logic p2 never dereference NULL*/
            p1 = (p1 -> next);
            p2 = (p2 -> next);
        }
        if(!stop)
            break;
    }
}
