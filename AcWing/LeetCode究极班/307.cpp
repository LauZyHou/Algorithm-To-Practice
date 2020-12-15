#define lowbit(x) (x&(-x))

class NumArray {
public:
    int n;
    vector<int> tr;
    vector<int> nums;

    // 查询[1..x]区间和（从1开始计下标）
    int query(int x) {
        int res = 0;
        for (int i = x; i; i -= lowbit(i))
            res += tr[i];
        return res;
    }

    // 原数组x位置加上c（从1开始计下标）
    void add(int x, int c) {
        for (int i = x; i <= n; i += lowbit(i))
            tr[i] += c;
    }

    NumArray(vector<int>& _nums) {
        nums = _nums;
        n = nums.size();
        tr.resize(n + 1);

        // O(n)的初始化方式
        vector<int> s(n + 1);
        // 计算前缀和数组s，利用它来初始化树状数组
        for (int i = 1; i <= n; i ++ ) {
            s[i] = s[i - 1] + nums[i - 1];
            tr[i] = s[i] - s[i - lowbit(i)];
        }
    }
    
    // 将nums[i]更新为val（从0开始计下标）
    void update(int i, int val) {
        add(i + 1, val - nums[i]);
        nums[i] = val;
    }
    
    // 求nums数组中区间[i, j]的区间和（从0开始计下标）
    int sumRange(int i, int j) {
        return query(j + 1) - query(i);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */