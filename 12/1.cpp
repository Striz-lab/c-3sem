#include <iostream>
#include <vector>
#include <set>
 
using namespace std;
 
bool is_DAG(int node_index, const vector<set<int>> &graph, vector<bool> used){
    used[node_index] = true;
    for (auto i : graph[node_index]){
        if (used[i])
            return false;
        bool check = is_DAG(i, graph, used);
        if (!check) return false;
        }
    return true;
    }
 
void dfs(int node_index, vector<set<int>> graph, vector<bool> &used, vector<int> &ans){
    used[node_index] = true;
    for (auto i : graph[node_index])
        if (!used[i]) dfs(i, graph, used, ans);
    ans.push_back (node_index);
    }

void topological_sort(vector<set<int>> graph, vector<bool> &used, vector<int> &ans){
    for (int i = 0; i < used.size(); i++)
        used[i] = false;
    ans.clear();
    for (int i = 0; i < graph.size(); i++){
        if (!used[i])
            dfs(i, graph, used, ans);
        }
 
    for (int i = 0; i < graph.size(); i ++)
        cout << ans[graph.size() - 1 - i] << " ";
        
    }
 
int main(){
    int n, m;
    cin >> n >> m;
    vector<set<int>> graph (n);
    for (int i = 0; i < n; i++) graph[i] = {};
    vector<bool> used (n, false);
    int a, b;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        graph[a].insert(b);
        }

    bool is_it_Dag = true;
    for (int i = 0; i < n; i++){
            if (is_DAG(i, graph, used) == false){
                is_it_Dag = false;
                break;
                }
        }
 
    vector<int> ans;
    if (is_it_Dag == false)
        cout << "NO";
    else
        topological_sort(graph, used, ans);
 
    return 0;
    }
 
