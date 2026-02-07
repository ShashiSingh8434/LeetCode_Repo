#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height) {
    int s = 0;
    int e = height.size() - 1;
    int area = 0;

    while (s < e) {
        int temp_area = min(height[s], height[e]) * (e - s);
        area = max(area, temp_area);

        if (height[s] < height[e]) {
            s++;
        } else {
            e--;
        }
    }
    return area;
}


int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout<<maxArea(height);
    return 0;
}