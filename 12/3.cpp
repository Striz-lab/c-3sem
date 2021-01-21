#include <iostream>
#include <vector>
#include <set>
 
using namespace std;
 
struct Edge{
    int start, finish, weight;
    };
 
int main(){
    const int INF = 15000000;
    vector<int> dist;
    vector<Edge> edges;
    int n, m, v;
    int a, b, w;
    cin >> n >> m >> v;
    Edge temp;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> w;
        temp.start = a;
        temp.finish = b;
        temp.weight = w;
        edges.push_back(temp);
        }
    dist.resize(n, INF);
    dist[v] = 0;
 
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m; j++){
            if (dist[edges[j].start] < INF){
                if (dist[edges[j].finish] > dist[edges[j].start] + edges[j].weight)
                    dist[edges[j].finish] = dist[edges[j].start] + edges[j].weight;
                }
            }
        }
    vector<int> copied = dist;
    for (int i = 0; i < 3; i++)
        {
        for(int j = 0; j < m; j++)
                {
                if (copied[edges[j].start] < INF)
                    {
                    if (copied[edges[j].finish] > copied[edges[j].start] + edges[j].weight)
                        copied[edges[j].finish] = copied[edges[j].start] + edges[j].weight;
                    }
                }
        }
 
 
    for (int i = 0; i < n; i ++){
        if (copied[i] == dist[i] && dist[i] < INF)
            cout << dist[i] << " ";
        else
            cout << "UDF ";
        }
 
    return 0;
    }
