class Solution {
public:
    vector<int> divingBoard(int s, int l, int k) {
        if(!k) {
            return vector<int>();
        }
        if(s == l) {
            vector<int> ans(1);
            ans[0] = k*s;
            return ans;
        }
        int j = 0;
        vector<int> ans(k+1);
        for(int i=0;i<k+1;i++) {
            ans[j++] = l*i + s*(k-i);
        }
        return ans;
    }
};