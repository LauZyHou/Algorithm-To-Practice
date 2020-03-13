class Solution {
public:
    vector<vector<int>> findContinuousSequence(int t) {
        // 两个数: (t-1) / 2 == 0
        // 三个数: (t-1-2) / 3 == 0
        // ...
        // 需要保证减掉之后大于0
        vector<vector<int>> ans;
        int i = 1;
        while(t>0) {
            t -= i;
            i++;
            if(t>0 && t%i==0) {
                vector<int> v(i);
                for(int j=0;j<i;j++)
                    v[j] = t/i + j;
                ans.push_back(v);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};