class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size(), base = 1e4;
        for (int i = 0; i < n; i ++ ) {
            // 如果超过base，说明是遍历过了
            if (nums[i] >= base) continue;
            int k = i; // 当前的位置
            int s = base + i; // 在当前位置打的标记
            bool t = nums[i] > 0; // 当前的符号
            int last = -1;
            do {
                int p = ((k + nums[k]) % n + n) % n; // 下一个位置
                last = nums[k]; // 记录最后的位置
                nums[k] = s; // 标记k位置
                k = p; // 跳到下一个位置
            } while (k != i && nums[k] < base && t == (nums[k] > 0)); // 没有遍历过，并且是符号相同的
            if (last % n && nums[k] == s) return true; // 不是自环，并且最终回到了这次遍历的环里面
        }
        return false;
    }
};