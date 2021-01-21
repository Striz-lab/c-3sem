#include <iostream>

template<typename T = int>
void bubble(T *a, int size){ // не зависит от того, что забирает, важно, что оно поддерживает опреатор меньше
    for (int i = 0; i != size; ++i){
        for (int j = 0; j != size - 1; ++j)
            if (a[j] > a[j+1]){
                std::swap(a[j], a[j+1]);
            }
    }
}
template<>
void bubble<bool>(bool *a, int size){ // не зависит от того, что забирает, важно, что оно поддерживает опреатор меньше
    int l = 0, r = size - 1;
    while (l < r){
        while (!a[l]) ++l;
        while (a[r]) --r;
        if (l <= r)
            std::swap(a[l], a[r]);
    }
}

//должен быть виден на этапе компиляции, должен быть поствлен в качестве исходного кода
//алгоритм компилируется по требованию
//захламление кодом -- для каждого типа создается новый кусок кода

int main(){
    int a[] = {8,6,9,3,7,3};
    double b[] = {7, 2.0, 1.8, 6};
    bool c[] = {1,0,0,0,0,0,1,1,1};
    
    bubble(a,6);
    bubble(b,4);
    bubble(c,9);
    
    for (auto x : a){
        std::cout << x << " ";
    }
    std::cout << std::endl;
    
    for (auto x : b){
        std::cout << x << " ";
    }
    std::cout << std::endl;
    
    for (auto x : c){
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}
