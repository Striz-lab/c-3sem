#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

#include <functional> // std::hash

struct Student{
    int age;
    std::string name;
};

bool operator==(Student const &lha, Student const &rha){
    return rha.age == lha.age and rha.name == lha.name;
}

namespace std{
template<>
struct hash<Student>{
    size_t operator()(Student const&s) const{
        return std::hash<int>()(s.age) ^ std::hash<std::string>()(s.name);
    }
};
}
 
int main(){
    std::unordered_set<std::string> hash_set;
    hash_set.insert("Hello");   // O(1)
    auto it = hash_set.find("Hello"); // O(1)
    hash_set.erase("Hello");//O(1)  на самом деле, при большой заполненности эта солжность выраждается в линейную, но такое мы не рассматриваем
    
    std::unordered_set<Student> Sset;
    Student Anna; Anna.age = 21; Anna.name = "Anna";
    Sset.insert(Anna);
    
    std::unordered_map<std::string, int> m; // словарь/отображение std::string --> int
    m.insert(std::pair<std::string, int>("Hello", 5));
    m.insert(std::pair<std::string, int>("World", 5));
    
    auto it2 = m.find("Hello");
    
    if (it2 != m.end())
        std::cout << it2->first << ' ' << it2->second << std::endl;
    return 0;
}
