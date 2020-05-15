class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& vv) {
        if(vv.empty())
            return vector<int>();
        int row = vv.size();
        int col = vv[0].size();
        int i = 0;
        vector<int> ans(row*col);
        int l = 0;
        int r = col-1;
        int t = 0;
        int b = row-1;
        while(true) {
            for(int j=l;j<=r;j++)
                ans[i++] = vv[t][j];
            if(++t > b)
                break;
            for(int j=t;j<=b;j++)
                ans[i++] = vv[j][r];
            if(--r < l)
                break;
            for(int j=r;j>=l;j--)
                ans[i++] = vv[b][j];
            if(--b < t)
                break;
            for(int j=b;j>=t;j--)
                ans[i++] = vv[j][l];
            if(++l > r)
                break;
        }
        return ans;
    }
};