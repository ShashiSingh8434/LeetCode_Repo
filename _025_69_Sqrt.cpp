#include <iostream>
using namespace std;

int mySqrt(int x) {
    if (x < 2) return x;
    
    long left = 1, right = x / 2;
    
    while (left <= right) {
        long mid = left + (right - left) / 2;
        
        if (mid == x / mid) {
            return mid;
        } 
        else if (mid < x / mid) {
            left = mid + 1;
        } 
        else {
            right = mid - 1;
        }
    }
    
    return right; 
}

int main(){
    
    return 0;
}