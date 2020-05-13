class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& vv) {
        if(vv.empty())
            return vector<int>();
        int row = vv.size();
        int col = vv[0].size();
        int n = row*col;
        vector<int> ans(n);
        int i = 0;
        int l = 0; // left
        int r = col-1; // right
        int t = 0; // top
        int d = row-1; // down
        while(true) {
            for(int j=l;j<=r;j++)
                ans[i++] = vv[t][j];
            if(++t > d)
                break;
            for(int j=t;j<=d;j++)
                ans[i++] = vv[j][r];
            if(--r < l)
                break;
            for(int j=r;j>=l;j--)
                ans[i++] = vv[d][j];
            if(--d < t)
                break;
            for(int j=d;j>=t;j--)
                ans[i++] = vv[j][l];
            if(++l > r)
                break;
        }
        return ans;
    }
};