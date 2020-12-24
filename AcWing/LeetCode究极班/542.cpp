#define x first
#define y second

typedef pair<int, int> PII;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return matrix;
        int n = matrix.size(), m = matrix[0].size();
        // 距离数组
        vector<vector<int>> dist(n, vector<int>(m, -1));
        // bfs队列
        queue<PII> q;
        // 先将所有的0插入到队列里
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
        // 四个方向
        int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
        while (q.size()) {
            auto t = q.front(); q.pop();
            for (int i = 0; i < 4; i ++ ) {
                int a = t.x + dx[i], b = t.y + dy[i];
                if (a >= 0 && a < n && b >= 0 && b < m && dist[a][b] == -1) {
                    dist[a][b] = dist[t.x][t.y] + 1;
                    q.push({a, b});
                }
            }
        }
        return dist;
    }
};