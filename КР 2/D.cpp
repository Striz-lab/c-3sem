#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int FINAL = 2;
const int BARRIER = 1;
const int FREE_SPACE = 0;

int w, h;
vector<vector<pair<int, int>>> g;
queue<pair<int, int>> q;

pair<int, int> left(int x, int y) {
    while (x > 0 && g[x][y].first == FREE_SPACE) {
        x--;
    }
    if (g[x][y].first == BARRIER) {
        x++;
    }
    return {x, y};
}

pair<int, int> right(int x, int y) {
    while (x < w - 1 && g[x][y].first == FREE_SPACE) {
        x++;
    }
    if (g[x][y].first == BARRIER) {
        x--;
    }
    return {x, y};
}

pair<int, int> top(int x, int y) {
    while (y > 0 && g[x][y].first == FREE_SPACE) {
        y--;
    }
    if (g[x][y].first == BARRIER) {
        y++;
    }
    return {x, y};
}
pair<int, int> bottom(int x, int y) {
    while (y < h - 1 && g[x][y].first == FREE_SPACE) {
        y++;
    }
    if (g[x][y].first == BARRIER) {
        y--;
    }
    return {x, y};
}

void bfs() {
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        int type = g[x][y].first;
        int time = g[x][y].second;
        if (type == FINAL) {
            cout << time << '\n';
            return;
        }
        vector<pair<int, int>> next_points = {left(x, y), right(x, y), top(x, y), bottom(x, y)};
        for (auto point : next_points) {
            if (g[point.first][point.second].second == -1) {
                g[point.first][point.second].second = time + 1;
                q.push(point);
            }
        }
    }
}

int main() {
    int64_t n, m;
    cin >> n >> m;
    w = n;
    h = m;
    g.assign(n, vector<pair<int, int>>(m, {0, -1}));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; j++) {
            int type;
            cin >> type;
            g[i][j].first = type;
        }
    }
    g[0][0].second = 0;
    q.push({0, 0});
    bfs();
    return 0;
}
