#define lowbit(x) (x&(-x))

const int mod = 1e9 + 7;

class Solution {
public:
    int m;
    vector<int> tr;

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

    int createSortedArray(vector<int>& v) {
        // 离散化很耗时间，这里直接取一下最大值作为树状数组的最大长度就不会超时
        m = *max_element(v.begin(), v.end());
        tr.resize(m + 1);

        int res = 0;
        for (int i = 0; i < v.size(); i ++ ) {
            res = (res + min(query(v[i] - 1), i - query(v[i]))) % mod;
            add(v[i], 1);
        }
        return res;
    }
};