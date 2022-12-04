/* Compute average weight for the set of the elephant seals in the file elephant_seal_data.txt.
 * Author: Ciro Bermudez
 * Compile: gcc -o output.exe t6.c
 * Run UNIX: output.exe < elephant_seal_data.txt
 * RUN Powershell: Get-Content elephant_seal_data.txt | output.exe
*/
#include <stdio.h>
#define POPULATION 1000

/* Compute the average*/
double average(int size, int data[]);

/* Read the data into an array*/
void read_data(int size, int data[]);

/* Print the array*/
void print_data(int size, int data[]);

/* Run this function alone to measure tha amount of numbers in the input file*/
void measure_array(void);

int main(void){

    int data[POPULATION] = {0};
    int samples = 10;
    printf("The population of elephants seals is: %d\n", POPULATION);
    read_data(POPULATION, data);
    printf("The first %d weights are: \n", samples);
    print_data(samples, data);           // print first 10 elements
    printf("...\n");
    printf("The average weight is: %.4lf\n", average(POPULATION, data) );

    return 0;
}


/* Compute the average*/
double average(int size, int data[]){
    int i;
    double avg = 0.0;
    //double sum = 0;
    for(i = 0; i < size; i++){
        avg += ( data[i] - avg ) / (i + 1);
        //sum += data[i];
    } 
    //return sum/size;
    return avg;
}

/* Read the data into an array*/
void read_data(int size, int data[]){
    int i;
    for(i = 0; i < size; i++){
        scanf("%d", data + i);
    }
}

/* Print the array*/
void print_data(int size, int data[]){
    int i;
    for(i = 0; i < size; i++){
        printf("i = %5d, %5d\n", i+1, data[i]);
    }
}

/* Run this function alone to measure tha amount of numbers in the file*/
void measure_array(void){
    int i, info;
    for(i = 0; scanf("%d", &info) == 1; i++){
    }
    printf("Array lenght = %d\n", i);
}
