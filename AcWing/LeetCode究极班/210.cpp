class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        vector<int> d(n);
        for (auto& e: edges) {
            int b = e[0], a = e[1];
            g[a].emplace_back(b);
            d[b] ++;
        }

        queue<int> q;
        for (int i = 0; i < n; i ++ )
            if (!d[i])
                q.push(i);
        
        vector<int> res;
        while (q.size()) {
            int t = q.front();
            q.pop();
            res.emplace_back(t);
            for (int i: g[t]) {
                if (-- d[i] == 0)
                    q.push(i);
            }
        }
        if (res.size() < n) res = {};
        return res;
    }
};