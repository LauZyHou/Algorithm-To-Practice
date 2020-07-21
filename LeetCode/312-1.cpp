class Solution {
public:
    vector<int> val;
    // f[i][j]表示val上(i,j)区间里问题的解, -1表示还没计算,用solve计算
    vector<vector<int>> f;

    int solve(int l, int r) {
        if(l >= r-1)
            return 0;
        if(f[l][r]!=-1)
            return f[l][r];
        for(int m=l+1;m<r;m++) {
            int s = val[l] * val[m] * val[r];
            s += solve(l, m) + solve(m, r);
            f[l][r] = max(f[l][r], s);
        }
        return f[l][r];
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        val.resize(n+2);
        val[0] = val[n+1] = 1;
        for(int i=1;i<=n;i++)
            val[i] = nums[i-1];
        f.resize(n+2, vector<int>(n+2, -1));
        return solve(0, n+1);
    }
};