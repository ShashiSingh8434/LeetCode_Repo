#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    return 0;
}

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int x = 0;

    while(x < n/2){
        int s = x;
        int e = n-x-1;

        int counter = x;
        int i = 0;
        while(counter < n-x-1){
            int temp = matrix[s][x+i];

            swap(matrix[s+i][e], temp);
            swap(matrix[e][e-i], temp);
            swap(matrix[e-i][s], temp);
            swap(matrix[s][s+i], temp);

            i++;
            counter++;
        }

        x++;
    }
}