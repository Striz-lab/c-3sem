#include <iostream>


template<typename T>
struct ListPair{// данные и указатель
    T data;
    ListPair *next;
    
};

template<typename T>//можно сунуть в методы)))
void walk(ListPair<T> *node){
    if (node){
        std::cout << node->data << std::endl;
        valk(node->next);
    }
}




template<size_t size = 10>
struct Vector{
    double a[size];
    
    Vector<size> operator+(Vector<size> const oth) const{
        Vector<size> res;
        for (int i = 0; i != size; ++i){
            res.a[i] = a[i] + oth.a[i];
            return res;
        }
    }
    
};


int main(){
    
    Vector<2> a;
    Vector<3> b; b.a[0] = 1; b.a[1] = 1; b.a[2] = 1;
    Vector<3> c; c.a[0] = 2; c.a[1] = 3; c.a[2] = 5;
    
    auto d = b + c;
    
    return 0;
}
