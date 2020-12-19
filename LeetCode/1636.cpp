class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        typedef pair<int, int> PII;
        unordered_map<int, int> cnt;
        for (auto x: nums) {
            cnt[x] ++ ;
        }
        vector<PII> vec;
        for (auto& [k, v]: cnt) {
            vec.push_back({v, -k});
        }
        sort(vec.begin(), vec.end());
        vector<int> res;
        for (int i = 0; i < vec.size(); i ++ )
            for (int j = 0; j < vec[i].first; j ++ )
                res.emplace_back(-vec[i].second);
        return res;
    }
};