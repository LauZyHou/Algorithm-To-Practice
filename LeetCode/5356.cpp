class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& vv) {
        vector<int> ans;
        set<int> st;
        int n = vv.size();
        if(!n)
            return ans;
        int m = vv[0].size();
        if(!m)
            return ans;
        for(int i=0;i<n;i++) {
            int rowmin = vv[i][0];
            for(int j=1;j<m;j++) {
                if(vv[i][j]<rowmin)
                    rowmin = vv[i][j];
            }
            st.insert(rowmin);
        }
        for(int j=0;j<m;j++) {
            int colmax = vv[0][j];
            for(int i=0;i<n;i++) {
                if(vv[i][j]>colmax)
                    colmax = vv[i][j];
            }
            if(st.count(colmax))
                ans.push_back(colmax);
        }
        return ans;
    }
};