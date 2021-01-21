#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(){
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }
    for (int i = 0; i < n; i++){
        if (A[i] % 4 == 0 and (A[i]/1000 != 4 and A[i]/1000 != 5))
            cout << A[i] << endl;
        else if (A[i] % 7 == 0 and (A[i]/1000 != 7 and A[i]/1000 != 1))
            cout << A[i] << endl;
        else if (A[i] % 9 == 0 and (A[i]/1000 != 9 and A[i]/1000 != 8))
            cout << A[i] << endl;
    }
return 0;
}
