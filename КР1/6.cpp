#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using std::cin;
using std::cout;
using std::set;
using std::vector;
using std::endl;

void thing(int &size, set<vector<int> > &set, int &N, vector<int> &arr){

    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            for (int k = j + 1; k < size; ++k) {
                for (int l = k + 1; l < size; ++l) {
                    if (arr[i] + arr[j] + arr[k] + arr[l] == N){
                        vector<int> numbers;
                        numbers.push_back(arr[i]);
                        numbers.push_back(arr[j]);
                        numbers.push_back(arr[k]);
                        numbers.push_back(arr[l]);
                        sort (numbers.begin(), numbers.end());
                        set.insert(numbers);
                    }
                }
            }
        }
    }

    for (auto it = set.begin(); it != set.end(); it++) {
            cout << (*it)[0] <<" "<< (*it)[1] << " " << (*it)[2] << " " << (*it)[3] << endl;
        }
}


int main(){
    
    
    int K;
    cin >> K;
    int inp;
    vector<int> arr;
    for (int i = 0; i < K; ++i) {
        cin >> inp;
        arr.push_back(inp);
    }
    
    set<vector<int> > set;
    int N;
    cin >> N;
    
    thing(K, set, N, arr);
    return 0;
}

