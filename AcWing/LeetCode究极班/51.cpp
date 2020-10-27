class Solution {
public:
    int n;
    vector<bool> col, dg, udg;
    vector<string> path;
    vector<vector<string>> ans;

    vector<vector<string>> solveNQueens(int _n) {
        n = _n;
        col = vector<bool>(n);
        dg = udg = vector<bool>(2 * n);
        path = vector<string>(n, string(n, '.'));
        ans.clear();

        dfs(0);

        return ans;
    }

    void dfs(int i) {
        if (i == n) {
            ans.emplace_back(path);
            return ;
        }
        for (int j = 0; j < n; j ++) {
            if (!col[j] && !dg[i + j] && !udg[i - j + n]) {
                col[j] = dg[i + j] = udg[i - j + n] = true;
                path[i][j] = 'Q';
                dfs(i + 1);
                col[j] = dg[i + j] = udg[i - j + n] = false;
                path[i][j] = '.';
            }
        }
    }
};