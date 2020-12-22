class Solution {
public:
    vector<int> f; // -1：没算过，1：必胜，0：必败
    int n, m;

    int dp(int x) {
        // 已经算过
        if (f[x] != -1) return f[x];
        // 还没算过，先计算总和
        int sum = 0;
        for (int i = 0; i < n; i ++ )
            if (x >> i & 1) // 如果当前这一位是1，那么就说明这个数选过了
                sum += i + 1;
        // 再枚举所有的没选过的位置
        for (int i = 0; i < n; i ++ ) {
            if (x >> i & 1) continue;
            if (sum + i + 1 >= m) return f[x] = 1; // 必胜的边界
            // 如果从某个位置往后走是必败状态，那么当前也是必胜的
            if (dp(x + (1 << i)) == 0) return f[x] = 1;
        }
        // 至此，当前是必败状态，因为每个后继都是必胜的
        return f[x] = 0;
    }

    bool canIWin(int _n, int _m) { // 能选的是1..n，需要达到的总和是m
        n = _n, m = _m;
        if (n * (n + 1) / 2 < m) return false; // 如果全报完都达不到m那是没法必胜的
        f.resize(1 << n, -1); // 状态的数量就是2的n次方，因为从1到n每个数就是选和不选，-1表示还没计算过
        return dp(0);
    }
};