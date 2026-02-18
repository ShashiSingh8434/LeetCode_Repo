#include <iostream>
#include <vector>
using namespace std;

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4

int search(vector<int>& nums, int target) {
    int s = 0, e = nums.size() - 1;

    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (nums[mid] == target) return mid;

        // left half sorted
        if (nums[s] <= nums[mid]) {
            if (nums[s] <= target && target < nums[mid]) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        // right half sorted
        else {
            if (nums[mid] < target && target <= nums[e]) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {4,5,6,7,8,1,2,3};
    cout<<search(nums,8);
    return 0;
}