/* Description of the program
 * Author: Ciro Bermudez
*/
#include <stdio.h>

/* Declare type*/
enum WeekDays {MON, TUE, WED, THU, FRI, SAT, SUN};

void print_day(enum WeekDays any_day){
    switch(any_day){
        case MON: printf(" Monday ");    break;
        case TUE: printf(" Tuesday ");   break;
        case WED: printf(" Wednesday "); break;
        case THU: printf(" Thursday ");  break;
        case FRI: printf(" Friday ");    break;
        case SAT: printf(" Saturday ");  break;
        case SUN: printf(" Sunday ");  break;
        default: printf(" %d is an error", any_day);
    }
}

enum WeekDays next_day(enum WeekDays any_day){
    return (any_day + 1) % 7;
}

enum WeekDays prev_day(enum WeekDays any_day){
    return any_day == MON ? SUN : (any_day - 1);
}

int main(void){
    enum WeekDays today = FRI;
    print_day(today);
    printf("\n\n");
    print_day(7);
    printf("\n\n");
    print_day( next_day(today) );
    printf("\n\n");
    print_day( prev_day(MON) );

    return 0;
}

