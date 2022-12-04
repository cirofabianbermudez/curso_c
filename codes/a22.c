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
    head = malloc(sizeof(list));
    printf("sizeof(list) = %lu\n", sizeof(list));
    head -> data = 5;
    head -> next = NULL;
    print_list(head, "single element list");
    printf("");
    return 0;
}

