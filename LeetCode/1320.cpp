class Solution {
private:
    int dist(int a, int b) {
        int xa = a / 6, ya = a % 6;
        int xb = b / 6, yb = b % 6;
        return abs(xa - xb) + abs(ya - yb);
    }
public:
    int minimumDistance(string word) {
        int n = word.size();
        // <当前打的字母位置，左手指位置，右手指位置>时的最优（小）解
        int dp[n][26][26];
        memset(dp, 0x3f, sizeof(dp)); // 这里>>1是为了防止+d时候溢出
        // 起始点费用是0，另一个手指可以是任何字母
        for (int i = 0; i < 26; i ++) {
            dp[0][i][word[0] - 'A'] = dp[0][word[0] - 'A'][i] = 0;
        }
        // 遍历每个要敲击的字母
        for (int i = 1; i < n; i ++) {
            // 当前字母（编号）
            int cur = word[i] - 'A';
            // 前一个字母（编号）
            int prev = word[i - 1] - 'A';
            // 两者的距离，仅当是用同一个手指打这两个字母的时候这个距离才有意义
            int d = dist(cur, prev);
            // 遍历任意的一个字母（编号）j，是另一个手指的当前位置
            for (int j = 0; j < 26; j ++) {
                // 左手指打的prev然后打cur，右手指保持j位置不变
                dp[i][cur][j] = min(dp[i][cur][j], dp[i - 1][prev][j] + d);
                // 右手指打的prev然后打cur，左手指保持j位置不变
                dp[i][j][cur] = min(dp[i][j][cur], dp[i - 1][j][prev] + d);
                // 如果j是prev，知“另一个手指”在i-1处打的prev
                // “当前手指”在i处打的是cur，i-1位置的“当前手指”在哪都行
                // 这里遍历一遍所有允许的位置
                if (j == prev) {
                    for (int k = 0; k < 26; k ++) {
                        int d0 = dist(cur, k);
                        dp[i][cur][prev] = min(dp[i][cur][prev], dp[i - 1][k][prev] + d0);
                        dp[i][prev][cur] = min(dp[i][prev][cur], dp[i - 1][prev][k] + d0);
                    }
                }
            }
        }
        
        // 最后一定是左手指或者右手指在word[n-1]位置，另一个在哪都有可能
        int end = word[n - 1] - 'A';
        int ans = INT_MAX;
        for (int k = 0; k < 26; k ++) {
            ans = min(ans, dp[n - 1][end][k]);
            ans = min(ans, dp[n - 1][k][end]);
        }
        return ans;
    }
};