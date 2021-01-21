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
    int a, b, m, n, t, k, s, state = 0;
    char c;
    string str;
    cin >> a >> n >> m;
    map<pair<int, char>, int> grath;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        grath.insert({ pair<int, char>(a, c), b });

    cin >> t;
    set<int> term;
    for (int i = 0; i < t; i++) {
        cin >> s;
        term.insert(s);
    }
    cin >> k;
    int* answers = new int [k];
    
    for (int i = 0; i < k; i++){
        cin >> str;
        for (int j = 0; j < str.size(); j++){
            auto cur = grath.find(pair<int, char>(state, str[j]));
            if (cur != grath.end())
                state = (*cur).second;
            else {
                state = -1;
                break;
            }
        }
        answers[i] = term.count(state); 
    }
    for (int i = 0; i < k - 1; i++)
        cout << answers[i] << " ";
    cout << answers[k - 1] << endl;
    return 0;
}


