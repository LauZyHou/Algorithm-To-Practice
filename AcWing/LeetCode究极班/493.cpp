#define lowbit(x) (x&(-x))

typedef long long LL;

class Solution {
public:
    vector<LL> numbers;

    int m;
    vector<int> tr;

    inline int get(LL x) {
        return lower_bound(numbers.begin(), numbers.end(), x) - numbers.begin() + 1;
    }

    int query(int x) {
        int res = 0;
        for (int i = x; i; i -= lowbit(i))
            res += tr[i];
        return res;
    }

    void add(int x, int c) {
        for (int i = x; i <= m; i += lowbit(i))
            tr[i] += c;
    }

    int reversePairs(vector<int>& nums) {
        // 离散化
        for (auto n: nums) {
            numbers.emplace_back(n);
            numbers.emplace_back((LL)n * 2);
        }
        sort(numbers.begin(), numbers.end());
        numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());
        // 树状数组
        m = numbers.size();
        tr.resize(m + 1);
        

        int res = 0;
        int n = nums.size();
        for (int i = n - 1; i >= 0; i -- ) {
            res += query(get(nums[i]) - 1);
            add(get((LL)nums[i] * 2), 1);
        }
        return res;
    }
};