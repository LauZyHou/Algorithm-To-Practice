class Solution {
public:
    vector<int> fraction(vector<int>& cont) {
        int len  = cont.size();
        if(!len)
            return vector<int> {1,0};
        vector<int> ans(2);
        ans[0] = cont[len-1]; // 分母
        ans[1] = 1; // 分子
        for(int j=len-2;j>=0;j--) {
            int t = ans[0];
            ans[0] = t * cont[j] + ans[1];
            ans[1] = t; 
        }
        return ans;
    }
};