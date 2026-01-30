#include <iostream>
#include <vector>
using namespace std;

int pivotIndex(vector<int>& nums) {

    int totalSum = 0;
    for(int i : nums){
        totalSum += i;
    }

    int leftSum = 0;

    for(int i = 0; i < nums.size(); i++){
        int rightSum = totalSum - leftSum - nums[i];

        if(leftSum == rightSum)
            return i;

        leftSum += nums[i];
    }

    return -1;



    // wrong method to approach this question using two pointer way 

    // int leftSum = 0;
    // int rightSum = 0;

    // int s = 0;
    // int e = nums.size()-1;

    
    // -----------------------------------------------------------------------------------
    // while(s != e){
    //     if(abs(leftSum + nums[s] - rightSum) < abs(rightSum + nums[e] - leftSum)){
    //         leftSum += nums[s];
    //         s++;
    //     }
    //     else{
    //         rightSum += nums[e];
    //         e--; 
    //     }

        
    //     cout<<leftSum<<" "<<rightSum<<endl;
    // }

    // -----------------------------------------------------------------------------------
    // while(s!=e){
    //     if(leftSum < rightSum){
    //         leftSum += nums[s];
    //         s++;
    //     }
    //     else if (leftSum > rightSum){
    //         rightSum += nums[e];
    //         e--;
    //     }
    //     else if (nums[s] < nums[e]){
    //         leftSum += nums[s];
    //         s++;
    //     }
    //     else if (nums[s] > nums[e]){
    //         rightSum += nums[e];
    //         e--;
    //     }
    //     else{
    //         rightSum += nums[e];
    //         e--;
    //     }

    //     cout<<leftSum<<" "<<rightSum<<endl;
    // }

    // if(leftSum == rightSum){
    //     return s;
    // }
    // else{
    //     return -1;
    // }

}

int main(){
    // [-1,-1,-1,-1,-1,0]
    vector<int> nums = {1,7,3,6,5,6};
    cout<<pivotIndex(nums);
    return 0;
}