class Solution {
public:
    vector<int> p;

    int find(int x) {
        if (p[x] != x)
            p[x] = find(p[x]);
        return p[x];
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        unordered_map<string, pair<string, int>> em_msg; // email -> {user_name, email_id}
        int emid = 0; // 当前扫到的email的id号，同时也是email并查集的结点数
        for (auto ac: acc) {
            auto uname = ac[0];
            for (int i = 1; i < ac.size(); i ++ ) {
                auto email = ac[i];
                if (!em_msg.count(email)) // 这个email第一次出现，记录一下
                    p.emplace_back(emid), em_msg[email] = { uname, emid ++ };
                // 和自己的任意一个email合并一下，如果已经出现过了，那么这个合并就能导致两个集合的合并
                p[find(em_msg[ac[1]].second)] = p[find(em_msg[ac[i]].second)];
            }
        }

        unordered_map<int, int> setid2residx; // 集合id到结果集下标的映射
        vector<vector<string>> res;
        for (auto& [e, msg]: em_msg) {
            int root = find(msg.second);
            if (!setid2residx.count(root)) {
                setid2residx[root] = res.size();
                vector<string> tmp;
                tmp.emplace_back(msg.first);
                res.emplace_back(tmp);
            }
            res[setid2residx[root]].emplace_back(e);
        }

        // email内部排序
        for (auto& vs: res) {
            sort(vs.begin() + 1, vs.end());
        }

        return res;
    }
};