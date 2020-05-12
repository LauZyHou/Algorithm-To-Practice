class Solution {
public:
    int expectNumber(vector<int>& s) {
        return set<int>(s.begin(), s.end()).size();
    }
};