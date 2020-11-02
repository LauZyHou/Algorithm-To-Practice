class Solution {
public:
    vector<vector<bool>> f;

    vector<vector<string>> partition(string s) {
        int n = s.size();
        f = vector<vector<bool>>(n, vector<bool>(n));

        for (int j = 0; j < n; j ++ )
            for (int i = 0; i <= j; i ++ ) {
                if (i == j)
                    f[i][j] = true;
                else if (s[i] == s[j]) {
                    f[i][j] = i + 1 == j || f[i + 1][j - 1];
                }
            }

        dfs(s, 0);
        return ans;
    }

    vector<vector<string>> ans;
    vector<string> path;

    void dfs(string& s, int u) {
        if (u == s.size())
            ans.emplace_back(path);
        else {
            for (int j = u; j < s.size(); j ++ ) {
                if (f[u][j]) {
                    path.emplace_back(s.substr(u, j - u + 1));
                    dfs(s, j + 1);
                    path.pop_back();
                }
            }
        }
    }
};