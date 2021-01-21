#include <iostream>
#include <string>

const int p = 1409;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string t, s;
    std::cin >> t >> s;
    
    bool okay = false;
    long long h_s = 0;
    long long h_t = 0;
    
    long long p_pow(1), h(1);
    if (s.size() > 100000){
    if (s.size() >= t.size()){
        for (int i = 0; i < t.size(); ++i){
            h_t += (t[i] - 'a' + 1) * p_pow;
            h_s += (s[i] - 'a' + 1) * p_pow;
            p_pow = p_pow * p;
        }
    }
    
    for (int i = 0; i < (1 + s.size() - t.size()); ++i){
        if (i){
            h_s = h_s - (s[i-1] - 'a' + 1) * h + (s[i + t.size() - 1] - 'a' + 1) * p_pow;
            p_pow *= p;
            h *= p;
        }
        if (h_s == h_t * h){
                  std::cout << i << ' ';
                  okay = true;
        }
    }
    }
    else{
        for (int i = 0; i < (1 + s.size() - t.size()); ++i){

                for(int j = 0; (j < t.size()) && (t[j] == s[i+j]); j++) {
                    if(j == (t.size()-1)) {
                      std::cout << i << ' ';
                      okay = true;
                    }
                }
        }
    }
    
    if (not okay)
        std::cout << -1;
        
    std::cout << "\n";
    return 0;
}
