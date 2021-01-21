#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <numeric>

int main(){
    int n;
    std::cin >> n;
    std::vector<std::vector<bool>> con(n, std::vector<bool>(n, false));
    std::vector<bool> visited(n, false);
    std::vector<int> queue = {0};
    visited[0] = true;

    int m;
    std::cin >> m;
    for (int i = 0; i < m; ++i){
        int a, b;
        std::cin >> a >> b;
        con[a][b] = true;
        con[b][a] = true;
    }
    
    while (queue.size()){
        for (int i = 0; i < n; ++i){
            if (con[queue[0]][i] && !visited[i]){
                visited[i] = true;
                queue.push_back(i);
            }
        }
        queue.erase(queue.begin());
    }

    int n_vis = 0;
    for (int i = 0; i < n; ++i)
        if (visited[i])
            n_vis++;


    if (n_vis == n)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
    
return 0;
}
