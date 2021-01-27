class Solution {
public:
    int k;
    multiset<int> left, right; // 左边大根堆，右边小根堆

    // 从对顶堆来计算中位数
    double get_medium() {
        // 如果k是奇数，直接返回最小堆里最小的元素
        if (k & 1) return *right.begin();
        // 否则是偶数，返回左边最大值和右边最小值的平均数
        return ((double)*left.rbegin() + *right.begin()) / 2;
    }

    // 在对顶堆里加入一个数
    void add(int x) {
        if (x >= *right.begin()) right.insert(x);
        else left.insert(x);
    }

    // 在对顶堆里删除一个数
    void remove(int x) {
        if (x >= *right.begin()) right.erase(right.find(x));
        else left.erase(left.find(x));
    }

    // 调整对顶堆
    void adjust() {
        // 左边不能比右边多
        while (left.size() > right.size()) {
            right.insert(*left.rbegin());
            left.erase(left.find(*left.rbegin()));
        }
        // 右边不能比左边多（如果k是奇数，不能多超过1）
        while (right.size() > left.size() + (k&1)) {
            left.insert(*right.begin());
            right.erase(right.find(*right.begin()));
        }
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int _k) {
        k = _k;
        // 由于窗口大小是k，所以先把前k个数放到对顶堆里面
        for (int i = 0; i < k; i ++ ) right.insert(nums[i]);
        // 再将前一半数放到左边（如果k是奇数，右边比左边多一个）
        for (int i = 0; i < k / 2; i ++ ) {
            left.insert(*right.begin()); // multiset的begin()是最小数的迭代器
            right.erase(right.begin());
        }
        vector<double> res;
        res.push_back(get_medium());
        // 将窗口滑动，然后每次求一下中位数
        for (int i = k; i < nums.size(); i ++ ) {
            // 每次加入nums[i]，删除nums[i - k]
            add(nums[i]), remove(nums[i - k]);
            adjust();
            res.push_back(get_medium());
        }
        return res;
    }
};