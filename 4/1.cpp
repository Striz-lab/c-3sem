#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(){
    int n, k = 0, f = 1;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        f = 1;
        for (int j = i + 1; j < n; j++)
            if (a[i] == a[j]) {
                f = 0;
                break;
            }
        if (f == 1)
            k++;
    }
    cout << k << endl;
return 0;
}
