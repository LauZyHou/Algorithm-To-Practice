class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int desire = 1;
        vector<string> res;
        for (auto u: target) {
            while (desire < u)
                res.emplace_back("Push"), res.emplace_back("Pop"), desire ++ ;
            res.emplace_back("Push"), desire ++ ;
        }
        return res;
    }
};