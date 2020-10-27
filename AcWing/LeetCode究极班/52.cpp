class Solution {
public:
    int n;
    vector<bool> col, dg, udg;

    int totalNQueens(int _n) {
        n = _n;
        col = vector<bool>(n);
        dg = udg = vector<bool>(2 * n);

        return dfs(0);
    }

    int dfs(int i) {
        if (i == n)
            return 1;
        
        int res = 0;
        for (int j = 0; j < n; j ++) {
            if (col[j] || dg[i + j] || udg[i - j + n])
                continue;
            col[j] = dg[i + j] = udg[i - j + n] = true;
            res += dfs(i + 1);
            col[j] = dg[i + j] = udg[i - j + n] = false;
        }

        return res;
    }
};