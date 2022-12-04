/* Open and read a file of integer pairs into an array that is created with the first
 * integer telling you how many to read. Write a routine that places these values into
 * a binary tree structure. Then walk the tree “inorder” and print these values to the screen.
 * Author: Ciro Bermudez
 * Compile: gcc -o output.exe t15.c
 * Execute: ./output.exe data.txt
 * data.txt  4 9 11 4 5
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node NODE;
typedef NODE *BTREE;


void print_array(int array[], int size);
void read_data(FILE *p, int array[]);
void inorder(BTREE root);
BTREE new_node(void);
BTREE init_node(int num, BTREE p1, BTREE p2);
BTREE create_tree(int a[], int i, int size);

int main(int argc, char *argv[]){
    /* Check number of terminal inputs */
    if (argc != 2) {
        printf("ERROR: The program needs one arguments: <input-file-name>\n");
        exit(1);
    }

    /* Open file for reading */
    FILE *ifp = fopen(argv[1], "r");

    /*Read first element of input text file*/
    int array_size = 0;
    fscanf(ifp,"%d", &array_size);

    /* Dynamically assing memory*/
    int *data;
    data = (int *)malloc( array_size * sizeof(int) );

    /* Check for errors */
    assert(data != NULL);

    /* Read data from the file and put it into the array*/
    read_data(ifp, data);

    /* Print results*/
    printf("The data consist of %d elements:\n", array_size);
    print_array(data, array_size);

    printf("The binary tree in order is:\n");
    BTREE b = create_tree(data, 0, array_size);
    inorder(b);

    /* Close file */
    fclose(ifp);

    return 0;
}

void print_array(int array[], int size){
    for (int i = 0; i < size; i++) {
        printf("%3d ", array[i] );
    }
    printf("\n");
}

void read_data(FILE *p, int array[]){
    int i = 0;
    while ( fscanf(p,"%d", &array[i]) == 1) {
        i++;
    }
}

void inorder(BTREE root){
    if (root != NULL) {
        inorder(root -> left);
        printf("%3d ", root -> data);
        inorder(root -> right);
    }
}

BTREE new_node(void){
    return malloc(sizeof(NODE));
}

BTREE init_node(int num, BTREE p1, BTREE p2){
    BTREE t;
    t = new_node();
    t -> data = num;
    t -> left = p1;
    t -> right = p2;
    return t;
}

BTREE create_tree(int a[], int i, int size){
    if (i >= size) {
        return NULL;
    } else {
        return init_node(a[i],
                create_tree(a, 2*i + 1, size), 
                create_tree(a, 2*i + 2, size) );
    }
}
