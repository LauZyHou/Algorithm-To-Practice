class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        vector<pair<int,int> > vp(n);
        for(int i=0;i<n;i++) {
            vp[i].first = accumulate(mat[i].begin(), mat[i].end(), 0);
            vp[i].second = i;
        }
        sort(vp.begin(), vp.end());
        vector<int> ans(k);
        for(int i=0;i<k;i++)
            ans[i] = vp[i].second;
        return ans;
    }
};