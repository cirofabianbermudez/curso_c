#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int sides = 6;
inline int r_sides(){
    return rand() % sides + 1; 
}

int main(void){
    cout << "Some text" << endl;

    return 0;
}


