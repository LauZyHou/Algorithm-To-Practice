// 状态数组，0表示false，1表示true，-1表示未计算
int f[2000][2000];

class Solution {
public:
    // 哈希表存石子位置->石子是第几个
    unordered_map<int, int> hash;
    // 每个石子的位置
    vector<int> stones;

    // 记忆化搜索
    int dp(int i, int j) {
        // 已经计算过
        if (f[i][j] != -1) return f[i][j];
        // 没有计算过，先置为false再计算能不能转移过来
        f[i][j] = 0;
        // 枚举上一次跳的是j-1/j/j+1长度，注意少跳一步
        for (int k = max(1, j - 1); k <= j + 1; k ++ )
            if (hash.count(stones[i] - k)) { // 确保这个位置有石头
                int p = hash[stones[i] - k]; // 这个位置是第几个石头
                if (dp(p, k)) { // 如果这个位置跳k步是可行的，就能转移过来
                    f[i][j] = 1;
                    break;
                }
            }
        return f[i][j];
    }

    bool canCross(vector<int>& _stones) {
        stones = _stones;
        int n = stones.size();
        for (int i = 0; i < n; i ++ )
            hash[stones[i]] = i;
        // 状态数组清空
        memset(f, -1, sizeof f);
        // 在第0个石子处只能跳1的距离，所以把f(0, 1)置为true
        f[0][1] = 1;
        // 枚举在最后一个石子，也就是i = n - 1位置，能够跳几步
        // 由于一共只有n个石子，所以在这个位置最多也就只能跳n-2/n-1/n步
        for (int j = 0; j < n; j ++ )
            if (dp(n - 1, j))
                return true;
        return false;
    }
};