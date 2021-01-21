#include <iostream>
#include <vector>
#include <algorithm>
#include <set>


using namespace std;


int getPrev(int v){
    if (v == p[v])
        return v;
    return p[v] = getPrev(p[v]);
}

bool join(int a, int b){
    a = getPrev(a);
    b = getPrev(b);
    if (a == b)
        return false;
    if (r[a] < r[b])
        std::swap(a, b);
    p[b] = a;
    if (r[a] == r[b])
        r[a]++;
    return true;
}

int main() {
    int n, m, k, w;

    const int maxn = 1e6 + 7;

    vector<vector<int>> edges;

    int p[maxn], r[maxn];
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b, c;
        std::cin >> a >> b >> c;
        edges.push_back({c, a - 1, b - 1});
    }
    for (int i = 0; i < n; i++)
        p[i] = i;
    cin >> k;
    if (k != n - 1){
        std::cout << "NO\n";
        return 0;
    }
    for (int i = 0; i < k; i++){
        int j;
        cin >> j;
        w += edges[j - 1][0];
        if (!join(edges[j - 1][1], edges[j - 1][2])){
            std::cout << "NO\n";
            return 0;
        }
    }
    for (int i = 0; i < n; i++)
        p[i] = i;
    sort(edges.begin(), edges.end());
    for (int i = 0; i < m; i++){
        if (join(edges[i][1], edges[i][2]))
            w -= edges[i][0];
    }
    if (w > 0)
        cout << "NO";
    else
        cout << "YES";
    return 0;
}
