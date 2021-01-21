#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void check_the_match(int *a, int &it, int k){
    int start = it;
    while (a[start] == a[it]) {
        it += k;
    }
    
}
 
void threeSum(int *nums, int &n) {
    
    std::sort(nums, nums + n);
    
    
    
    for (int it = 0; it < n; check_the_match(nums, it, 1)) {
        int left = it + 1;
        int right = n - 1;
        while (left < right) {
            int sum = nums[it] + nums[left] + nums[right];
            if (sum == 0) {
                std::cout << nums[it] << " " <<  nums[left] << " " << nums[right] << " ";
                check_the_match(nums, left, 1);
                check_the_match(nums, right, -1);
            } else{
                if (sum < 0) {
                    check_the_match(nums, left, 1);
                } else {
                    check_the_match(nums, right, -1);
                }
            }
        }
    }
    
}

int main(){
    
    
    int a;
    std::cin >> a;
    int* array = new int[a];
    
    for (int i = 0; i < a; ++i){
        std::cin >> array[i];
    }
    
    threeSum(array, a);
    
    
    
    std::cout << std::endl;
    
    delete [] array;
    
    return 0;
}
