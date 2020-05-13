class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& vv) {
        int m = vv.size();
        if(!m)
            return vector<int>();
        int n = vv[0].size();
        if(!n)
            return vector<int>();
        vector<int> ans(m*n);
        int i = 0; // 索引ans
        int s = 0; // 索引vv横纵坐标之和
        int maxs = m+n-2;
        while(s <= maxs) {
            // 左下到右上
            int x1 = min(s, m-1);
            int y1 = s-x1;
            while(x1>=0 && y1<=n-1)
                ans[i++] = vv[x1--][y1++];
            s++;

            if(s > maxs)
                break;
            
            // 右上到左下
            int y2 = min(s, n-1);
            int x2 = s-y2;
            while(y2>=0 && x2<=m-1)
                ans[i++] = vv[x2++][y2--];
            s++;
        }
        return ans;
    }
};