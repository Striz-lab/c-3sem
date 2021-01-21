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

int main(){
    int a, b, m, n, t, k, s;
    char c;
    string str;
    cin >> a >> n >> m;
    map<pair<int, char>, set<int>> grath;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        auto f = grath.find(pair<int, char>(a, c));
        if (f != grath.end())
            (*f).second.insert(b);
        else
            grath.insert({pair<int, char>(a, c), set<int>{b} });
    }
    cin >> t;
    set<int> term;
    for (int i = 0; i < t; i++) {
        cin >> s;
        term.insert(s);
    }
    cin >> k;
    int* answers = new int [k];
    
    for (int i = 0; i < k; i++){
        set<int> cur_state = {0};
        set<int> next_state;
        cin >> str;
        for (int j = 0; j < str.size(); j++){
            for (int state : cur_state){
                auto cur = grath.find(pair<int, char>(state, str[j]));
                if (cur != grath.end())
                    for (int state1 : (*cur).second)
                        next_state.insert(state1);
                }
            cur_state = next_state;
            next_state.clear();
            if (cur_state.empty())
                break;
            }
        answers[i] = 0;
        for (int state : cur_state)
            if (term.count(state)){
                answers[i] = 1;
                break;
            }
        }
    
    for (int i = 0; i < k - 1; i++)
        cout << answers[i] << " ";
    cout << answers[k - 1] << endl;
    return 0;
}


