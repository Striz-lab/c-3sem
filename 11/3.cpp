#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <numeric>
#include <set>


int main(){
    int n;
    std::cin >> n;
    std::vector<std::vector<bool>> con(n, std::vector<bool>(n, false));

    int m;
    std::cin >> m;

    for (int i = 0; i < m; ++i){
        int a, b;
        std::cin >> a >> b;
        con[a][b] = true;
        con[b][a] = true;
    }
    std::vector<int> dist(n, n);
    dist[0] = 0;

    int step = 1;

    std::set<int> upd = {0};
    while (find(dist.begin(), dist.end(), n) != dist.end()){
        std::set<int> np;
        for (auto it = upd.begin(); it != upd.end(); it++){
            for (int i = 0; i < n; ++i)
            {
                if (con[*it][i] && dist[i] == n){
                    np.insert(i);
                    dist[i] = step;
                }
            }
        }
        upd = np;
        ++step;
    }

    for (int i = 0; i < n; ++i)
    {
        std::cout << dist[i] << std::endl;
    }

    return 0;
}
