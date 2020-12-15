#define lowbit(x) (x&(-x))

const int M = 1e4 + 10;
const int N = 2 * M;

int tr[N];

class Solution {
public:
    int query(int x) {
        int res = 0;
        for (int i = x; i; i -= lowbit(i))
            res += tr[i];
        return res;
    }

    void add(int x, int c) {
        for (int i = x; i <= N; i += lowbit(i))
            tr[i] += c;
    }

    vector<int> countSmaller(vector<int>& nums) {
        memset(tr, 0, sizeof tr);
        int n = nums.size();
        vector<int> res(n);
        for (int i = n; i >= 1; i -- ) {
            int y = nums[i - 1] + M;
            res[i - 1] = query(y - 1);
            add(y, 1);
        }
        return res;
    }
};