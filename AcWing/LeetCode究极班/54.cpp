class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int n = matrix.size();
        if (!n) return res;
        int m = matrix[0].size();
        if (!m) return res;

        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        vector<vector<bool>> st(n, vector<bool>(m, false));

        for (int i = 0, x = 0, y = 0, d = 0; i < m * n; i ++) {
            st[x][y] = true;
            res.emplace_back(matrix[x][y]);

            // 新方向
            int a = x + dx[d], b = y + dy[d];
            // 走到不能走的位置了
            if (a < 0 || a >= n || b < 0 || b >= m || st[a][b]) {
                d = (d + 1) % 4;
                a = x + dx[d], b = y + dy[d];
            }

            x = a, y = b;
        }
        
        return res;
    }
};