class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        // 拓扑排序：先统计所有点入度，每次取入度为0的进行BFS
        vector<vector<int>> g(n);
        vector<int> d(n);

        for (auto& e: edges) {
            int a = e[0], b = e[1];
            g[b].emplace_back(a);
            d[a] ++;
        }

        queue<int> q;
        for (int i = 0; i < n; i ++ )
            if (!d[i])
                q.push(i);
        
        int cnt = 0;
        while (q.size()) {
            int t = q.front();
            q.pop();
            cnt ++;
            for (int i: g[t]) {
                if (-- d[i] == 0)
                    q.push(i);
            }
        }

        return cnt == n;
    }
};