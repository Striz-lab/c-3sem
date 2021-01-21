#include <iostream>
#include <map>
#include <stack>

int main(int argc, const char * argv[]) {
    std::map <std::string, int (*)(int, int)> ops {
        {"+", [](int a, int b) {return a + b;}},
        {"-", [](int a, int b) {return a - b;}},
        {"*", [](int a, int b) {return a * b;}},
        {"/", [](int a, int b) {return a / b;}}
    };
    
    std::stack<int> numbers;
    std::string inp;
    while (std::cin >> inp) {
        if (ops.find(inp) == ops.end()) {
            numbers.push(std::stoi(inp));
        } else {
            int b = numbers.top(); numbers.pop();
            int a = numbers.top(); numbers.pop();
            numbers.push(ops.at(inp)(a, b));
        }
    }
    
    std::cout << numbers.top() << std::endl;
    
    return 0;
}
