/* 
 * Author: Ciro Bermudez
 * Compile: gcc -o output.exe t7.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum  department {HR, SALES, RESEARCH, SOFTWARE, EXECUTIVE};
typedef enum department department;

struct member {
    department job;
    int anual_salary;
    unsigned int ssn;
};
typedef struct member member;

/* Generate a salary base in the department and random raise*/
int salary_generator(department job){
    int salary;
    switch (job) {
        case HR:        salary = 71210;  break;
        case SALES:     salary = 38840;  break;
        case RESEARCH:  salary = 142650; break;
        case SOFTWARE:  salary = 120990; break;
        case EXECUTIVE: salary = 213020; break;
        default: salary = 54132;
    }
    return salary + ( rand() % (10000 + 1) );
}

/* Generate ssn with 9 numbers*/
unsigned int ssn_generator(void){
    return rand() % ( 999999999 + 1) ;
}

/* Select a random departmet*/
department department_generator(void){
    return rand() % (4 + 1);
}

/* Print all information of a employee*/
void print_employee(member employee){
    printf("Department: ");
    switch (employee.job) {
        case HR:        printf("HR       ");  break;
        case SALES:     printf("SALES    ");  break;
        case RESEARCH:  printf("RESEARCH ");  break;
        case SOFTWARE:  printf("SOFTWARE ");  break;
        case EXECUTIVE: printf("EXECUTIVE");  break;
        default: printf("Not a valid department");
    }
    printf(", Salary: %7d, SSN: %d\n", employee.anual_salary, employee.ssn);
}

int main(void){
    /* Seed random number generator*/
    srand(time(NULL));

    /* Create 10 employees*/
    member employees[10];

    int i;
    for (i = 0; i < 10; i++ ){
        /* random job*/
        department rand_job = department_generator();

        employees[i] = (member) {rand_job, salary_generator(rand_job), ssn_generator() };
        print_employee( employees[i] );
    }


    return 0;
}
