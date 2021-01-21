#include "Complex.h"
#include<iostream>

int main( ) {
    _Complex double z1, z2, z3;
    std::cout << "Введите 2 комплексных числа" << std::endl;
    std::cin >> z1 >> z2;
    std::cout << "Введите интересующий оператор" << std::endl;
    char op;
    std::cin >> op;
    
    switch (op){
        case'+': z3 = z1 + z2;
            break;
        case'-': z3 = z1 - z2;
            break;
        case'*': z3 = z1 * z2;
            break;
        case'/': z3 = z1/z2;
            break;
        default:
            std::cout << "lol" << std::flush;
    }
    
std::cout << z1 << ' ' << op << ' ' << z2 << " = " << z3 << std::flush;
    
}
