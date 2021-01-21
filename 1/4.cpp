#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;


int pod(vector<string> A, long long unsigned int a, long long unsigned int b){
    if (b < A.size()){
        for (long long unsigned int i = a; i <= b; i++)
            cout << A[i] << " ";
        if (a < A.size()-1)
            cout << endl;
        if (a < b)
            pod(A, ++a, b);
        else
            pod(A, 0, ++b);
    }
    return 0;
}

int main(){
vector<string> A;
string j;
while (cin >> j)
    A.push_back(j);

pod(A, 0, 0);
return 0;
}
