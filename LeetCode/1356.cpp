class Solution {
private:
    static bool cmp(const int& a, const int& b) {
        int anum = 0;
        int bnum = 0;
        int _a = a, _b = b;
        while(_a) {
            anum += _a&1;
            _a >>= 1;
        }
        while(_b) {
            bnum += _b&1;
            _b >>= 1;
        }
        if(anum==bnum)
            return a < b;
        return anum < bnum;
    }
public:
    vector<int> sortByBits(vector<int>& v) {
        sort(v.begin(), v.end(), cmp);
        return v;
    }
};