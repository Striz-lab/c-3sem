#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(){
    int n;

    cin>>n;
    vector<int> set;
    vector<int> set_bool(n,0);


    for(int i=0; i<n;i++){
        int x,y;
        cin>>x>>y;
        if(x+y+1 == n){
            if (set_bool[x]==0) {
                set.push_back(x);
                set_bool[x]=1;
            }
        }
    }
    cout<<set.size()<<endl;
    return 0;
}
