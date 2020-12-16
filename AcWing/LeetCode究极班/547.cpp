class Solution {
public:
    vector<int> p; // 并查集

    int find(int x) {
        if (x != p[x])
            p[x] = find(p[x]);
        return p[x];
    }

    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        for (int i = 0; i < n; i ++ )
            p.emplace_back(i);
        // 最开始每个人是单独的集合，所以朋友圈数量是n
        int cnt = n;
        for (int i = 0; i < n; i ++ ) {
            for (int j = 0; j < n; j ++ ) {
                if (M[i][j]) {
                    int a = find(i), b = find(j);
                    if (a != b) {
                        p[a] = p[b];
                        cnt -- ; // 每合并一次集合数量就减少1
                    }
                }
            }
        }
        return cnt;
    }
};