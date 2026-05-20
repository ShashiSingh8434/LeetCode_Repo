#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main(){
    
    return 0;
}

void setZeroes(vector<vector<int>>& matrix) {
    unordered_set<int> zero_row;
    unordered_set<int> zero_col;
    
    int row = matrix.size()-1;
    int col = matrix[0].size()-1;
    
    for(int i = 0; i <= row; i++){
        for(int j = 0; j <= col; j++){
            if(matrix[i][j] == 0){
                zero_row.insert(i);
                zero_col.insert(j);
            }
        }
    }

    for(int i = 0; i <= row; i++){
        bool flag = false;
        if(zero_row.find(i) != zero_row.end()){
            flag = true;
        }   

        for(int j = 0; j <= col; j++){
            if(flag){
                matrix[i][j] = 0;
            }
            else{
                if(zero_col.find(j) != zero_col.end()){
                    matrix[i][j] = 0;
                }
            }
        }
    }
}