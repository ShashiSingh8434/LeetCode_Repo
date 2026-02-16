#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size()-1;

    while(left <= right){
        if(nums[left] == target){
            return left;
        }
        if(nums[right] == target){
            return right;
        }
        if(nums[left] < target){
            left++;
        }
        if(nums[right] > target){
            right--;
        }
    }
    return -1;
}

int main(){
    
    return 0;
}