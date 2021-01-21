#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>


//если захотеть, то можно создать сруктуру и для неё создавать сет

struct Student{
    int age;
    std::string name;
};

bool operator<(Student const &lha, Student const &rha){
    return lha.name < rha.name;
}

struct AgeSmp{
    bool operator()(Student const &lha, Student const &rha) const{
        return lha.age < rha.age;
    }
};



int main(){
    std::vector<int>  a = {1,2,3,4,0,0,0,0,5,6,7,89};
    std::set<int> s(a.begin(), a.end()); // можно задать поэлементно, а можно с точки зрения итераторов, всегда можно добавить в сет
    s.insert(13); //не нужно тспользовать итераторы, так как это красно-черное дерево и элемент вставляется на своё место
    auto it = s.find(13);
    
    std::cout << *it << std::endl;
    
    s.erase(13); // все операции 9,10,11 -- за logN
    
    for (auto x : s){
        std::cout << x << ' ';
    }
    std::cout << std::endl;
    
    
    std::multiset<int> ms(a.begin(), a.end());
    for (auto x : ms){
        std::cout << x << ' ';
    }
    std::cout << std::endl;
    
    std::cout << s.count(0) << std::endl;
    std::cout << ms.count(0) << std::endl;
    
    
    std::set<Student, AgeSmp> students;
    Student Anna; Anna.name = "Anna"; Anna.age =21;
    Student Alex; Alex.name = "Alexey"; Alex.age =22;
    students.insert(Anna);
    students.insert(Alex);
    
    auto it1 = students.find(Anna);
    std::cout << it1->name << std::endl;
    
    std::map<std::string, int> m; // словарь/отображение std::string --> int
    m.insert(std::pair<std::string, int>("Hello", 5));
    m.insert(std::pair<std::string, int>("World", 5));
    
    auto it2 = m.find("Hello");
    
    if (it2 != m.end())
        std::cout << it2->first << ' ' << it2->second << std::endl;
    
    
    return 0;
}
