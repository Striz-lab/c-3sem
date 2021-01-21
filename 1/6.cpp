#include <iostream>
#include <vector>

const long long Q = 947;

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> field(n);
    for (int i = 0; i < n; ++i) {
        cin >> field[i];
    }
    vector<int> colors(n);
    for (int i = 0; i < n; ++i) {
        cin >> colors[i];
    }
    vector<int> dp(n);
    dp[0] = 1;
    for (int i = 0; i < n - 1; ++i) {
        if (field[i + 1] == colors[i] || field[i + 1] == field[i]) {
            dp[i + 1] = (dp[i + 1] + dp[i]) % Q;
        }
        if (i + 2 < n) {
            if (field[i + 2] == colors[i] || field[i + 2] == field[i]) {
                dp[i + 2] = (dp[i + 2] + dp[i]) % Q;
            }
        }
    }
    cout << dp[n - 1] << '\n';
    return 0;
}
