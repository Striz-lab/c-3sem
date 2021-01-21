#include <iostream>
#include <vector>

/*template <typename Iterator>  //Итератор -- универсальное средство доступа
void walk(Iterator begin, Iterator end){
    for (; begining != end; ++begin)
        std::cout << *begin << std::endl;
}*/

void print_int(int i){
    std::cout << i << std::endl;
}

void for_each(int *begin, int*end){             //универсально для всех типов, даже уже существующих
    for (int *it = begin; begin != end; ++begin){
        std::cout << *it << std::endl;
    }
}

int main(){
    std::vector<int> a = {1,2,3,5};
    std::for_each(a.begin(), a.end(), print_int);
    
    int b[] = {1,2,3,7};
    std::for_each(b, b + 4, print_int);
    for(auto x : a){  //работает на всем, где обеспечен итератор и метод begin() //с обычными массивами с выделением памяти не работает
        std::cout << x << std::endl;
    }
    
    for(auto it = std::begin(a); it != std::end(a); ++it){  //то же самое, что и предыдущий цикл
        auto x = *it;
        std::cout << x << std::endl;
    }
    return 0;
}
