class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> combinationSum3(int k, int n) {
        // 搜索组合，人为定义一个顺序，即只能从前往后搜，所以要有一个start，只能从start开始搜
        dfs(1, n, k);
        return ans;
    }

    void dfs(int start, int n, int k) {
        if (!n) { // 当前之和是0
            if (!k) { // 已经选了k个数
                ans.emplace_back(path);
                return ;
            }
        }
        else if (k > 0) { // 还有数可以选
            // 选下一个数
            for (int i = start; i <= 9; i ++ ) {
                if (n >= i) {
                    path.emplace_back(i);
                    dfs(i + 1, n - i, k - 1);
                    path.pop_back();
                }
            }
        }
    }
};