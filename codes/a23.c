/* Link lists
 * Author: Ciro Bermudez
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct list {
    int data;
    struct list *next;
};

typedef struct list list;

int is_empty(const list *l){
    return (l == NULL);
}

list *create_list(int d){
    list *head = malloc(sizeof(list));
    head -> data = d;
    head -> next = NULL;
    return head;
}

list *add_to_front(int d, list *h){
    list *head = create_list(d);
    head -> next = h;
    return head;
}

list *array_to_list(int d[], int size){
    list *head = create_list(d[0]);
    for (int i = 1; i < size; i++) {
        head = add_to_front(d[i], head);
    }
    return head;
}

void print_list(list *h, char *title){
    printf("%s\n", title);
    while (h != NULL) {
        printf("%d :", h -> data);
        h = h -> next;
    }
}

int main(void){

    list list_of_int;
    list *head = NULL;
    list *temphead = NULL;
    int data[3] = {2,3,5};
    head = array_to_list(data,3);
    //printf("head = %p, data = %d, next = %p\n", head, head -> data, head -> next);
    temphead = head;
    head = ( (head -> next) -> next) -> next;
    if (head == NULL)
        printf("Problems\n");
    //printf("data = %d\n",  head -> data );
    //print_list(head, "Complete list");
    //printf("\n\n");
    //head = add_to_front(10, head);
    //print_list(head, "Complete list");
    //printf("\n\n");
    return 0;
}


