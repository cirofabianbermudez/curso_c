/* Doubly linked list, remove duplicates in the linked list.
 * The data will be integers generated at random from [0,49] 
 * with 200 element at the start.
 * Author: Ciro Bermudez
 * Compile: gcc -o output.exe t13.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct list {
    int data;
    struct list *next;
    struct list *previous;
};

typedef struct list list;

list *create_element(int value);
list *add_to_front(list *head, list *new_element);
void print_list(list **head);
int num_of_list_elem(list **head);
void swap(list *p1, list *p2);
void bubble(list *head, int size);
void delete_repetitions(list **head);

int main(void){
    /* Seed random number generator*/
    srand(time(NULL));
    int list_size = 200;
    int max_rand_value = 49;

    /* Random number between 0-max_rand_value, fisrt element of linked list*/
    list *head = create_element( rand() % ( max_rand_value + 1 ) );
    for (int i = 0; i < list_size - 1 ; i++) {
        head = add_to_front( head, create_element( rand() % ( max_rand_value + 1 ) ) );
    }

    printf("Unsorted data\n");
    print_list(&head);

    printf("\n");
    bubble(head, list_size);

    printf("Sorted data\n");
    print_list(&head);

    printf("\n");
    delete_repetitions(&head);


    printf("Sorted data without repetitions\n");
    print_list(&head);
    return 0;
}

/* Delete all duplicates in a sorted linked list with pointer to pointer technique*/
void delete_repetitions(list **head){
    list **t1 = head;
    list **t2 = &(*head)->next;
    list *old;

    while ( (*t2) != NULL) {
        if ( (*t1)->data  == (*t2)->data ) {
            /* Save the content of t2*/
            old = *t2;
            /* Put the content of *t2 in *t1*/
            (*t1)->next = (*t2)->next;
            /* *t2 no longer has the direction of the second element 
             * so we use old to free the memory*/
            free(old);
        } else {
            t1 = &(*t1)->next;
            t2 = &(*t2)->next;
        }
    }
}

/* Create a single element linked list */
list *create_element(int value){
    list *head = (list *) malloc(sizeof(list));
    head -> data = value;
    head -> next = NULL;
    head -> previous = NULL;
    return head;
}

/* Add to front of the linked list and return the new head*/
list *add_to_front(list *head, list *new_element){
    head -> previous = new_element;
    new_element -> next = head;
    return new_element;
}

/* Simple print list function with pointer to pointer technique*/
void print_list(list **head){
    list **tracer = head;
    int i = 0;
    while ((*tracer) != NULL) {
        if (i % 10 == 0 && i != 0) {
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

