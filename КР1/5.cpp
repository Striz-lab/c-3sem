#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

std::string get(std::string s, int i0){
    std::string ans="";
    for(int i = i0; i< i0 + 10; i++)
        ans+=s[i];
    return ans;
}

void ans(std::string &s){
    std::string cr;
    std::set<std::string> st;
    std::set<std::string> ans;
    for(int i = 0; i < (int)s.length() - 9; i++){
        cr = get(s, i);
        if(st.find(cr)!=st.end()){
                ans.insert(cr);
        }
        else{
            st.insert(cr);
        }
    }
    for(std::string x:ans){
        std::cout << x << " ";
    }
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s;
    std::cin >> s;
    
    ans(s);
    
    std::cout << std::endl;
    return 0;
}
