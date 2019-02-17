#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string S) {
        int len = S.size();
        int _min = 0, _max = len;
        vector<int> ans(len + 1);
        for(int i = 0; i <= len; i++) {
            if('I' == S[i]) {
                ans[i] = _min++;
            } else {
                ans[i] = _max--;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    //todo
    return 0;
}
