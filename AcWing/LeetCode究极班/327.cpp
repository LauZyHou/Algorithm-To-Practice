#define lowbit(x) (x&(-x))

typedef long long LL;

class Solution {
public:
    int m; // 树状数组的长度
    vector<int> tr; // 树状数组，因为只存出现了多少次，所以int完全够用
    vector<LL> numbers; // 存离散化的结果

    void add(int x, int c) {
        for (int i = x; i <= m; i += lowbit(i))
            tr[i] += c;
    }

    int query(int x) {
        int res = 0;
        for (int i = x; i; i -= lowbit(i))
            res += tr[i];
        return res;
    }

    // 离散化取数，即看一下x在numbers中的下标，返回下标+1
    int get(LL x) {
        // 直接返回二分出来的迭代器结果的下标+1
        return lower_bound(numbers.begin(), numbers.end(), x) - numbers.begin() + 1;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<LL> s(n + 1);

        numbers.push_back(0); // 0也要被离散化，作为区间最左边界

        for (int i = 1; i <= n; i ++ ) {
            s[i] = s[i - 1] + nums[i - 1];
            // 要离散化的数
            numbers.push_back(s[i]);
            numbers.push_back(s[i] - lower);
            numbers.push_back(s[i] - upper - 1);
        }
        // 离散化：排序判重
        sort(numbers.begin(), numbers.end());
        numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());

        // 树状数组的元信息
        m = numbers.size();
        tr.resize(m + 1);

        // 求答案，即对每个数的离散化的结果看一下在树状数组里指定区间内的数有多少个
        int res = 0;
        add(get(0), 1); // 在树状数组中加入0离散化之后的结果，因为求区间是需要这个点的
        for (int i = 1; i <= n; i ++ ) {
            res += query(get(s[i] - lower)) - query(get(s[i] - upper - 1));
            // 每次求完之后，要把当前的s[i]的离散化结果加入到树状数组中
            // 这样才能保证每次遍历到i的时候树状数组里总是前面的所有数（的离散化结果）
            add(get(s[i]), 1);
        }

        return res;
    }
};