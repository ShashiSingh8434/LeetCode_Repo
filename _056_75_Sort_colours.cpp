#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    return 0;
}

void swap(vector<int>& nums, int a, int b){
    int temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
}

void sortColors(vector<int>& nums) {
    int n = nums.size();

    int a = 0;
    int c = n-1;
    int i = 0;

    while(i<=c){
        if(nums[i] == 0){
            swap(nums, a, i);
            a++;
            i++;
        }
        else if(nums[i] == 2){
            swap(nums, c, i);
            c--;
        }
        else{
            i++;
        }
    }
    
}