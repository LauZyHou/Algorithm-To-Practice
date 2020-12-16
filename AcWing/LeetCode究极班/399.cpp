class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // 转化成图论问题，两个点之间的除法取值就是两个点之间连接一条有向边
        // 用floyd来求一个点到另一个点的距离就可以了
        // 哈希表存一下图里面的所有结点
        unordered_set<string> vers;
        // 哈希表存一下图里面的两点之间的距离
        unordered_map<string, unordered_map<string, double>> d;
        // 枚举一下所有的方程
        for (int i = 0; i < equations.size(); i ++ ) {
            // 从a到b的距离是c
            auto a = equations[i][0], b = equations[i][1];
            auto c = values[i];
            d[a][b] = c, d[b][a] = 1 / c;
            // 将结点也加入到结点的哈希表里
            vers.insert(a), vers.insert(b);
        }

        // floyd算法
        for (auto k: vers) // 跳点
            for (auto i: vers) // 起点
                for (auto j: vers) // 终点
                    if (d[i].count(k) && d[k].count(j))
                        d[i][j] = d[i][k] * d[k][j];
        
        // 枚举所有的询问，求一下所有答案
        vector<double> res;
        for (auto q: queries) {
            auto a = q[0], b = q[1];
            if (d[a].count(b))
                res.emplace_back(d[a][b]);
            else
                res.emplace_back(-1);
        }
        return res;
    }
};