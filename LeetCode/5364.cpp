class Solution {
public:
    vector<int> createTargetArray(vector<int>& v, vector<int>& idx) {
        int len = v.size();
        vector<int> ans;
        for(int i=0;i<len;i++) {
            ans.insert(ans.begin()+idx[i], v[i]);
        }
        return ans;
    }
};