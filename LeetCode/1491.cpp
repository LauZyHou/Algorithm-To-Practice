class Solution {
public:
    double average(vector<int>& salary) {
        int _min = INT_MAX, _max = INT_MIN;
        int res = 0;
        for (auto a: salary) {
            res += a;
            if (a < _min) _min = a;
            if (a > _max) _max = a;
        }
        return (double)(res - _min - _max) / (salary.size() - 2);
    }
};