class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& v) {
        int len = v.size();
        unordered_map<int,vector<int>> g;
        for(int i=0;i<len;i++) {
            g[v[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for(auto& pair : g) {
            int size = pair.first;
            vector<int>& ids = pair.second;
            for(auto it=ids.begin();it!=ids.end();it+=size) {
                ans.push_back(vector<int>(it, it+size));
            }
        }
        return ans;
    }
};