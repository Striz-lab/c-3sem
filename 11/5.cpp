#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <numeric>
#include <set>

int main(){
    int n, m;
    std::cin >> n >> m;

    std::vector<int> place(n);
    std::vector<std::set<int>> cls(n);
    for (int i = 0; i < n; ++i){
        cls[i] = {i};
        place[i] = i;
    }

    int step = 0;

    while (cls[0].size() != n){
        int a, b;
        std::cin >> a >> b;
        int x, y;
        x = std::min(place[a], place[b]);
        y = std::max(place[a], place[b]);

        cls[x].insert(cls[y].begin(), cls[y].end());

        int tp = place[y];
        for (auto it : cls[place[tp]]){
            place[it] = place[x];
        }
        step++;
    }

    std::cout << step << std::endl;

return 0;
}
