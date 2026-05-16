#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    return 0;
}

int majorityElement(vector<int>& nums) {
    int ans = nums[0];
    int count = 0;

    for(int i : nums){
        if(count == 0){
            ans = i;
        }

        if(i == ans){
            count++;
        }
        else{
            count--;
        }            
    }
    return ans;
}