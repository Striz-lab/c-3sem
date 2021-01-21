#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> g;
vector<bool> used;
vector<int> tin, tout;
int timer;
int answer = -1;

void dfs (int v, int p = -1) {
    used[v] = true;
    ++timer;
    tin[v] = timer;
    tout[v] = timer;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i].first;
        int w = g[v][i].second;
        if (to == p)  {
            continue;
        }
        if (used[to]) {
            tout[v] = min(tout[v], tin[to]);
        }
        else {
            dfs (to, v);
            tout[v] = min(tout[v], tout[to]);
            if (tout[to] > tin[v]) {
                answer = max(answer, w);
            }
        }
    }
}

void find_bridges() {
    dfs(0);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t n, m;
    cin >> n >> m;
    used.assign(n, false);
    tin.resize(n);
    tout.resize(n);
    g.resize(n);
    for (int i = 0; i < m; ++i) {
        int f, t, c;
        cin >> f >> t >> c;
        f--;
        t--;
        g[f].push_back({t, c});
        g[t].push_back({f, c});
    }
    find_bridges();
    cout << answer;
    return 0;
}
