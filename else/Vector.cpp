#include "Vector.h"

size_t length(){
    return isfull;
}

void push_back(int x){
        if (isfull == size){
            size ++;
            int* tmp = new int[size];
            for (int i = 0; i < isfull; ++i)
                tmp[i] = stack[i];
            delete[] stack;
            stack = tmp;
        }
        stack[isfull] = x;
        isfull++;
    }
    
T pop_back(){
        isfull--;
    }
    
T print(){
    for (int i = isfull - 1; i >= 0; --i)
        std::cout << data[i] << ' ';
}
       
int top(){
    return data[isfull - 1];
}
    
Vector<T>& operator+(Vector<T>& V1){
        Vector<T> new_vec = new Vector<T>(this->_size + other._size);
        for (int i = 0; i < this->_size; i++)
            new_vec.ptr[i] = this->ptr[i];
        for (int i = 0; i < other._size; i++)
            new_vec.ptr[i + this->_size] = other.ptr[i];
        return new_vec;
}

Vector<T>& operator-(Vector<T>& V1){
        Vector<T> new_vec = new Vector<T>(this->_size + other._size);
        for (int i = 0; i < this->_size; i++)
            new_vec.ptr[i] = this->ptr[i];
        for (int i = 0; i < other._size; i++)
            new_vec.ptr[i + this->_size] = other.ptr[i];
        return new_vec;
}

T operator[](int i) {
    if (i < this->_size)
        return (this->ptr)[i];
    else
        throw -1;
}


