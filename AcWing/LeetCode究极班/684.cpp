class Solution {
public:
    vector<int> p;

    int find(int x) {
        if (x != p[x])
            p[x] = find(p[x]);
        return p[x];
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        p.emplace_back(0);
        for (int i = 1; i <= n; i ++ ) p.emplace_back(i);
        for (auto e: edges) {
            int a = find(e[0]), b = find(e[1]);
            if (a == b) return e;
            p[a] = b;
        }
        return {};
    }
};