#include <iostream>
// using namespace std;

long long fact(int n){
    long long f = 1;
    for (int i = 1; i <= n; i++) {
        f *= i;
    }
    return f;
}

int main(void){
    std::cout << "This program uses some features not in C89\n";

    for (auto i = 0; i < 16; i++) {
        std::cout << "factorial of " << i << " is " << fact(i) << std::endl;
    }
    std::cout << " Thats all folks!" << std::endl;

}

