#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    return 0;
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int left = m+n-1;
    int i1 = m-1;
    int i2 = n-1;

    while(left >= 0){
        if(i1 >= 0 && i2 >= 0){
            if(nums1[i1] >= nums2[i2]){
                nums1[left] = nums1[i1];
                i1--;
            }
            else{
                nums1[left] = nums2[i2];
                i2--;
            }
        }
        else if(i1 >= 0){
            nums1[left] = nums1[i1];
            i1--;
        }
        else if(i2 >= 0){
            nums1[left] = nums2[i2];
            i2--;
        }
        
        left--;
    }
}