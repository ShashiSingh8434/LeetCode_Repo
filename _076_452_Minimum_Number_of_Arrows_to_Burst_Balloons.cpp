#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    
    return 0;
}

int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end());

    int arrows = 1;
    long long end = points[0][1];

    for(int i = 1; i < points.size(); i++) {
        if(points[i][0] <= end) {
            end = min(end, (long long)points[i][1]);
        }
        else {
            arrows++;
            end = points[i][1];
        }
    }

    return arrows;
}