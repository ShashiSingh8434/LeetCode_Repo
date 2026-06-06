#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    return 0;
}
int mostWordsFound(vector<string>& sentences) {
    int ans = 0;

    for (string& s : sentences) {
        int words = 1;

        for (char c : s) {
            if (c == ' ')
                words++;
        }

        ans = max(ans, words);
    }

    return ans;
}