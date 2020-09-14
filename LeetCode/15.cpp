class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        vector<vector<int>> ans;
        int n = v.size();
        sort(v.begin(), v.end());
        if(n<3)
            return ans;
        for(int i=0;i<n-2;i++) {
            if(i>0 && v[i]==v[i-1])
                continue;
            int k = n-1;
            for(int j=i+1;j<k;j++) {
                if(j>i+1 && v[j]==v[j-1])
                    continue;
                while(j<k && v[i]+v[j]+v[k] > 0)
                    k--;
                if(j<k && v[i]+v[j]+v[k]==0) {
                    ans.push_back({v[i], v[j], v[k]});
                }
            }
        }
        return ans;
    }
};