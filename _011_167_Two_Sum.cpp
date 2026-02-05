#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& num, int target) {
    int left = 0;
    int right = num.size() - 1;

    while(left < right){

        if(num[left] + num[right] == target){
            return {left+1, right+1};
        }
        else if(num[right] > target - num[left] ){
            right--;
        }
        else{
            left++;
        }
    }
    return {1,2};
}

int main(){
    
    return 0;
}