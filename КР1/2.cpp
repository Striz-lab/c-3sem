#include <iostream>
#include <vector>
#include <string>
#include <stack>

using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::stack;

vector<string> parse(string s)
{
    string cr = "";
    bool tmp = false;
    vector<string> ans;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '<')
            tmp = true;
        if(s[i] == '>')
        {
            ans.push_back(cr);
            tmp = false;
            cr = "";
        }
        if(tmp and s[i] != '<')
            cr += s[i];
    }
    return ans;
}


int main()
{
    string s;
    stack<string> st;
    getline(cin, s);
    if(s[0] != '<' or s[s.length()-1] != '>'){
        cout<< "NO";
        return 0;
    }
    vector<string> parsed = parse(s);
    for(int i = 0; i < parsed.size(); i++)
    {
        if(parsed[i][0] != '/' )
        {
            if(st.size() == 0 and i != 0)
            {
                cout << "NO";
                return 0;
            }
            st.push(parsed[i]);
        }
        else
        {

            string tmp;
            if(st.size() == 0)
            {
                cout << "NO";
                return 0;
            }
            tmp = st.top();
            st.pop();
            if('/' + tmp != parsed[i])
            {
                cout << "NO";
                return 0;
            }
        }
    }

    if(st.size() != 0)
        cout << "NO";
    else
        cout << "YES";
 
    return 0;
 
}
