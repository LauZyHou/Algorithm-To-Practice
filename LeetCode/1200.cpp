class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& v) {
        sort(v.begin(), v.end());
        int len = v.size();
        vector<vector<int>> ans;
        if(!len)
            return ans;
        int minDiff = v[1]-v[0];
        for(int i=2;i<len;i++) {
            if(v[i]-v[i-1]<minDiff)
                minDiff = v[i]-v[i-1];
        }
        for(int i=1;i<len;i++) {
            if(v[i]-v[i-1]==minDiff)
                ans.push_back(vector<int>({v[i-1],v[i]}));
        }
        return ans;
    }
};