#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::vector<int> a = {1,2,3,4,5,6,7,8};
    std::cout << a[3] << std::endl;
    
    a.push_back(2);     // амортизированная константная сложность
    a.insert(a.begin(), 5); // O(n)
    a.erase(a.begin()); // O(n)
    
    
    std::vector<int> b;
    b.reserve(10000);
    
    
    for (auto it = a.begin(); it != a.end(); ++it)
        std::cout << *it << ' ' ;
    
    std::cout << std::endl;
    
    std::sort(b.begin(), b.end()); //на всякий случай
    return 0;
}

