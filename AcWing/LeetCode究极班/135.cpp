class Solution {
public:
    vector<int> w;
    int n;
    vector<int> f; // 记忆化搜索

    int candy(vector<int>& ratings) {
        w = ratings;
        n = ratings.size();
        f.resize(n, -1); // -1表示没计算过

        // 计算每个人分的糖果
        int res = 0;
        for (int i = 0; i < n; i ++ )
            res += dp(i);
        return res;
    }

    int dp(int x) {
        if (f[x] != -1)
            return f[x];
        f[x] = 1; // 至少分一个糖果
        if (x - 1 >= 0 && w[x] > w[x - 1])
            f[x] = max(f[x], dp(x - 1) + 1); // 因为x-1和x+1也不一定算过，所以这里还是要写dp，不能写f
        if (x + 1 < n && w[x] > w[x + 1])
            f[x] = max(f[x], dp(x + 1) + 1);
        return f[x];
    }
};