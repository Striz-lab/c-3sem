#include <chrono>
#include <iostream>
#include "RBTree.h"





#define START_TIMER  start = std::chrono::steady_clock::now();
#define STOP_TIMER  finish = std::chrono::steady_clock::now(); diff = finish - start;
#define GIVE_TIME  diff.count();


int main()
{
    // DON'T TOUCH
    double time;  // ms
    std::chrono::time_point<std::chrono::steady_clock> start, finish;
    std::chrono::duration<double, std::milli> diff;
    // END OF DON'T TOUCH

    START_TIMER
    RBTree tree;

    int j = 0, n = 80;
    if (n > 100)
        n = 100;        // Maximum 100 nodes
        while (j < n) {
            Integer num(rand() % 100 + 1);
            Node* node;
            int c = tree.find(&num, tree.root()/*, &node*/);
            if (c != 0) { // if value is not in the tree
                Integer* v = new Integer(num);
                tree.insert(node, v, c);
                ++j;
            }
        }
    
    
    
    std::cout << tree.size() << " ";
    STOP_TIMER
    std::cout << GIVE_TIME;
    std::cout << " " << std::endl;

   

    return 0;
}
