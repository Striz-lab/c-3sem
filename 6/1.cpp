#include <iostream>
#include <vector>
#include <string>
#include <map>

using std::cin;
using std::cout;
using std::vector;
using std::map;
using std::pair;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, i, key, value;
    cin >> n >> m;
    char op;
    vector<map<pair<int, int>, int> > ops(100000);
    
    for (int j = 0; j < m; ++j){
        cin >> i >> op >> key >> value;
            if (op == '+')
                ops[key * (i + 1) % 100000][{i, key}] = value;
            if (op == '?'){
                auto place = ops[key * (i + 1) % 100000].find({i, key});
                if (place != ops[key * (i + 1) % 100000].end())
                    cout << place->second << "\n";
                else
                    cout << value << "\n";
            }
            if (op == '-')
                ops[key * (i + 1) % 100000].erase({i, key});
    }
    return 0;
}
