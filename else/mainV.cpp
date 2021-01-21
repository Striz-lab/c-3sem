#include <iostream>
#include "Vector.h"


int main(){
    Vector<int> s(0);
    
    int n, i = 0 ;
    std::cin >> n;
    while (n){
        s.push_back(n);
        i++;
        std::cin >> n;
    }
    
    for (int i = 0; i < s.length(); i++)
        std::cout << s[i] << std::endl;

    return 0;
}

