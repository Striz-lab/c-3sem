#include <iostream>
#include <vector>

struct node{
    int ind;
    int r;
    int m;
};

int main(){
    int n, m = 0, i;
    long long unsigned int j;
    bool b = false;
    std::cin >> n;
    int A[n], B[n], C[n];
    std::vector<node> D;
    node E;
    E.r = 1;
    for (i = 0; i < n; i++){
        std::cin >> A[i] >> B[i] >> C[i];
        if (A[i] > m)
            m = A[i];
        for (j = 0; j < D.size(); j++)
            if (A[i] == D[j].ind){
                b = true;
                D[j].r++;
                D[j].m += C[i];
            }
        if (not b){
            E.ind = A[i];
            E.m = C[i];
            D.push_back(E);
        }
        b = false;
    }
    for (i = 0; i <= m; i++)
        for (j = 0; j < D.size(); j++)
            if (D[j].ind == i)
                std::cout << D[j].ind << " " << D[j].r << " " << D[j].m << std::endl;
    return 0;
}

