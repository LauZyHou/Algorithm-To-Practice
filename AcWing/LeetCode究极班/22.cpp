class Solution {
public:
    vector<string> ans;

    vector<string> generateParenthesis(int n) {
        // 1.任意前缀中左括号数量大于等于右括号数量
        // 2.左右括号总数量相等
        // 如果这题不用返回所有方案，而只是返回数量，那就是直接是用卡特兰数C_{2n}^n / (n + 1)
        // 用dfs做
        // 填左括号，只要lcnt < n
        // 填右括号，只要rcnt < lcnt && rcnt < n
        dfs(n, 0, 0, "");
        return ans;
    }

    void dfs(int n, int lc, int rc, string seq) {
        if (lc == n && rc == n) {
            ans.push_back(seq);
            return;
        }
        if (lc < n)
            dfs(n, lc + 1, rc, seq + '(');
        if (rc < lc) // 只写rc < lc就可以，因为rc < n一定是比这个弱的条件
            dfs(n, lc, rc + 1, seq + ')');
    }
};