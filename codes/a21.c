/* Description of the program
 * Author: Ciro Bermudez
*/
#include <stdio.h>

#define MAX_LEN   1000
#define EMPTY      -1
#define FULL      (MAX_LEN - 1)

enum boolean {false, true};

struct stack {
    char s[MAX_LEN];
    int top;
};

typedef enum boolean boolean;
typedef struct stack stack;

void reset(stack *stkp){
    stkp -> top = EMPTY;
}

void push(char c, stack *stkp){
    //(stkp -> top)++;
    //stkp -> s[stkp -> top] = c;
    stkp -> s[++(stkp -> top)] = c;
}

char pop(stack *stkp){
    return stkp -> s[(stkp -> top)--];
}

/* const because any value of the stack input should not change
 * if change an error will pop*/
char top(const stack *stkp){
    //stkp -> s[stkp -> top] = 'X';
    return stkp -> s[stkp -> top];
}

boolean empty(const stack *stkp){
    return (boolean)(stkp -> top == EMPTY);
}

boolean full(const stack *stkp){
    return (boolean)(stkp -> top == FULL);
}

int main(void){

    char str[] = "My name is Ciro Bermudez";
    printf("el caracter es: %c\n",*(str+1));
    int i;
    stack s1;
    reset(&s1);
    printf(" In the string: %s\n",str);
    for (i = 0; str[i] != '\0'; i++){
        if ( !full(&s1) ){
            push(str[i], &s1);
        }
    }
    printf(" From the stack: ");
    while ( !empty(&s1) ){
       // putchar( top(&s1) );
       // pop(&s1);
        putchar( pop(&s1) );
    }
    putchar('\n');

    return 0;
}

