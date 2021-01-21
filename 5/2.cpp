#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::string;

struct decoder{
    int statea;
    int stateb;
    char symba;
    char symbb;
};

int main(){
    long long unsigned int i;
    int j, n, state;
    char c;
    string stra, strb;
    cin >> n;
    n *= 4;
    decoder* Decoder = new decoder[n];
    
    for (j = 0; j < n; j++)
        cin >> Decoder[j].statea >> Decoder[j].symba >> Decoder[j].stateb >> Decoder[j].symbb;
    
    while (cin >> c)
        strb.push_back(c);
    
    for (j = 0; j < n; j++)
        if (Decoder[j].statea == 1 && Decoder[j].symbb == strb[0]){
            stra.push_back(Decoder[j].symba);
            state = Decoder[j].stateb;
        }
    
    for (i = 1; i < strb.size(); i++)
        for (j = 0; j < n; j++)
            if (Decoder[j].statea == state && Decoder[j].symbb == strb[i]){
                stra.push_back(Decoder[j].symba);
                state = Decoder[j].stateb;
                break;
            }
    
    for (i = 0; i < stra.size(); i++)
        cout << stra[i];
    cout << endl;
    
    delete[] Decoder;
    
    return 0;
}
