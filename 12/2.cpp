#include <iostream>
#include <vector>
#include <set>
 
using namespace std;
 
vector<vector<int>> graph;
 
vector<int> children;
 
set<int> ans;
bool* used;
int* tin;
int* fup;
int timer = 0;
 
void dfs(int v, int parent = -1){
    used[v] = true;
    tin[v] = fup[v] = timer++;
    children[v] = 0;
    for (auto to : graph[v]){
        if (to == parent) continue;
        if (used[to])
            fup[v] = min(fup[v], tin[to]);
        else
            {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            if (fup[to] >= tin[v] && parent != -1)
                ans.insert(v);
            children[v]++;
            }
 
        }
    if (parent == -1 && children[v] > 1)
        ans.insert(v);
    }
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n , m;
    cin >> n >> m;
    graph = vector<vector<int>> (n, vector<int> (0));
    used = new bool[n];
    children = vector<int> (n, 0);
    for (int i = 0; i < n; i++) used[i] = false;
    tin = new int[n];
    fup = new int[n];
    int a, b;
    for (int i = 0; i < m; i++)
        {
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
        }
    dfs(0);
    if (ans.empty())
        cout << -1;
    else{
        for (auto it : ans)
            cout << it + 1 << " ";
        }
    delete[] fup;
    delete[] used;
    delete[] tin;
    return 0;
    }
 
