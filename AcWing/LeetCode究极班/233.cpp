class Solution {
public:
    int countDigitOne(int n) {
        if (n <= 0) return 0;
        // 先把n的每一位取出来
        vector<int> nums;
        while (n) {
            nums.emplace_back(n % 10);
            n /= 10;
        }
        reverse(nums.begin(), nums.end());
        // 计算出现次数
        int res = 0;
        for (int i = 0; i < nums.size(); i ++ ) {
            int d = nums[i]; // 当前这一位
            // 计算一下y总的视频里的abc, efg, 1000这三个量
            int left = 0, right = 0, p = 1;
            for (int j = 0; j < i; j ++ )
                left = left * 10 + nums[j];
            for (int j = i + 1; j < nums.size(); j ++ )
                right = right * 10 + nums[j], p = p * 10;
            // 对当前这位分三种情况来看
            if (d == 0) res += left * p;
            else if (d == 1) res += left * p + right + 1;
            else res += (left + 1) * p;
        }
        return res;
    }
};