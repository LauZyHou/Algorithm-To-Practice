class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int x, int y) {
            string a = to_string(x), b = to_string(y);
            return a + b > b + a; // 从大到小排序
        });
        string res;
        for (int v: nums)
            res += to_string(v);
        // 去掉前导0
        int k = 0;
        while (k < res.size() - 1 && res[k] == '0')
            k ++;
        res = res.substr(k);
        return res;
    }
};