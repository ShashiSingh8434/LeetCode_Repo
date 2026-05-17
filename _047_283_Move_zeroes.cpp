#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    return 0;
}

void moveZeroes(vector<int>& nums) {
    int zero = 0;
    int left = 0;
    for(int i = 0; i<nums.size(); i++){
        if(nums[i] == 0){
            zero++;
        }
        else{
            nums[left] = nums[i];
            left++;
        }
    }

    for(int i = nums.size()-1; zero > 0; i--){
        nums[i] = 0;
        zero--;
    }

}