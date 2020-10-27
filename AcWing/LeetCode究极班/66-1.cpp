class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int t = 1;
        for (auto& x : digits) {
            t += x;
            x = t % 10; // 会直接修改digits里的数
            t /= 10;
        }
        if (t)
            digits.emplace_back(t);
        
        reverse(digits.begin(), digits.end());
        return digits;
    }
};