#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int count = 0;
    int unique = nums[0];

    for (int i = 1; i < nums.size(); i++){
        if(nums[i] != nums[count]){
            nums[++count] = nums[i];
        }
    }
    return count + 1;
}

// [0,0,1,1,1,2,2,3,3,4]
// [0,4,1,1,1,2,2,3,3, 0]
// [0,1,4,1,1,2,2,3,3, 0]

int main(){
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    cout<<endl<<removeDuplicates(nums);
    return 0;
}