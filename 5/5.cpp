#include <iostream>
#include <set>
#include <map>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::set;
using std::map;
using std::pair;
using std::string;

set<int> dfs(int cur, int n, int** list) {
    list[cur][cur] = 2;
    for (int i = 0; i < n; i++) {
        if (list[cur][i] == 1) {
            list[cur][i] = 2;
            auto eqs = dfs(i, n, list);
            for (int j = 0; j < n; j++)
                if (!list[cur][j] && eqs.count(j))
                    list[cur][j] = 2;
        }
        else if (list[cur][i] == 2)
            for (int j = 0; j < n; j++)
                if (list[i][j] && !list[cur][j])
                    list[cur][j] = 2;
    }
    set<int> ret;
    for (int i = 0; i < n; i++)
        if (list[cur][i])
            ret.insert(i);
    return ret;
}

int main()
{
    int a, n, m;
    cin >> a >> n >> m;

    map<pair<int, char>, set<int>> grath;
    int** list = new int* [n];
    for (int i = 0; i < n; i++) {
        list[i] = new int[n];
        for (int j = 0; j < n; j++)
            list[i][j] = 0;
        list[i][i] = 1;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        if (c == 'E') {
            list[a][b] = 1;
            continue;
        }
        auto f = grath.find(pair<int, char>(a, c));
        if (f != grath.end())
            (*f).second.insert(b);
        else
            grath.insert({ { a, c }, set<int>{b}});
    }

    for (int i = 0; i < n; i++)
        if (list[i][i] != 2)
            dfs(i, n, list);
    for (auto thing : grath) {
        set<int> new_st;
        for (int key : thing.second)
            for (int i = 0; i < n; i++)
                if (list[key][i])
                    new_st.insert(i);
        for (int st : new_st)
            grath.at(thing.first).insert(st);
    }

    int t;
    cin >> t;
    set<int> term;
    for (int i = 0; i < t; i++) {
        int s;
        cin >> s;
        term.insert(s);
    }

    int k;
    cin >> k;

    int* ans = new int[k];
    for (int i = 0; i < k; i++) {
        set<int> cur_state;
        for (int j = 0; j < n; j++)
            if (list[0][j])
                cur_state.insert(j);
        set<int> next_state;
        string str;
        cin >> str;
        for (int j = 0; j < str.size(); j++) {
            for (int state : cur_state) {
                auto cur = grath.find(pair<int, char>(state, str[j]));
                if (cur != grath.end())
                    for (int st : (*cur).second)
                        next_state.insert(st);
            }
            cur_state = next_state;
            next_state.clear();
            if (cur_state.empty()) break;
        }
        ans[i] = 0;
        for (int state : cur_state)
            if (term.count(state)) {
                ans[i] = 1;
                break;
            }
    }
    for (int i = 0; i < k - 1; i++)
        cout << ans[i] << " ";
    cout << ans[k - 1] << endl;
    delete[] ans;
    for (int i = 0; i < n; i++)
        delete[] list[i];
    delete[] list;
    return 0;
}
