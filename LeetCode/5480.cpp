class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& vv) {
        set<int> source;
        for(int i=0;i<n;i++) {
            source.insert(i);
        }
        for(auto& x : vv) {
            source.erase(x[1]);
        }
        vector<int> ret;
        for(int k:source)
            ret.push_back(k);
        return ret;
    }
};