class Solution {
public:
    vector<int> s;
    int n;

    Solution(vector<int>& w) {
        n = w.size();
        s.resize(n + 1);
        for (int i = 1; i <= n; i ++ ) s[i] = s[i - 1] + w[i - 1];
    }
    
    int pickIndex() {
        // 随机产生1到sum的数
        int k = rand() % s.back() + 1;
        // 二分去找第一个>=k的那个数，所在的下标
        int l = 1, r = n;
        while (l < r) {
            int mid = l + r >> 1;
            if (s[mid] >= k) r = mid;
            else l = mid + 1;
        }
        return r - 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */