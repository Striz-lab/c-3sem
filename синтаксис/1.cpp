#include <iostream>
#include <list>


int main(){
    std::list<int> a = {1,2,3,4,5,6,7}; // 1 >> 2 >> 3
    a.insert(a.begin(), -1); // O(1)
    a.push_back(10);
    a.push_front(2);
    
    for (auto it = a.begin(); it != a.end(); ++it)
        std::cout << *it << ' ' ;
    
    std::cout << std::endl;
    
    a.sort(); //на всякий
    return 0;
    
}
