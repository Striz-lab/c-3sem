#include<iostream>
#include<stack>
#include<cmath>
 
int main()
{
    int i, j;
    std::stack<int> a;
    std::cin >> j;
    while (j != 0){
        if (j > 0)
            a.push(j);
        if (not a.empty() && j < 0){
            if (std::abs(j) < std::abs(a.top())){
                i = a.top() + j;
                a.pop();
                a.push(i);
            }
            else
                a.pop();
        }
        std::cin >> j;
    }
        
    if (not a.empty())
        std::cout << a.size() << " " << a.top() << std::endl;
    else
                std::cout << a.size() << " " << -1 << std::endl;
                
    return 0;
}
