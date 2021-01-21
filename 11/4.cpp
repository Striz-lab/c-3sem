#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <numeric>
#include <set>

int main(){
    int n;
    std::cin >> n;
    int x, y;
    std::cin >> x >> y;
    x--;
    y--;
    std::vector<std::vector<int>> mat(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            std::cin >> mat[i][j];
            if (mat[i][j] == -1){
                mat[i][j] = 32000000;
            }
        }
    }
    for (int k = 0; k < n; ++k){
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                mat[i][j] = std::min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }

    if (mat[x][y] == 32000000){
        std::cout << "-1" << std::endl;
        exit(0);
    }

    std::cout << mat[x][y] << std::endl;

    return 0;
}
