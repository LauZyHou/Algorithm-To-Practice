class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> S; // 存储所有的单词
        for (auto& s: bank) S.insert(s);
        unordered_map<string, int> dist; // 存储从起始点到每个位置的距离
        dist[start] = 0;
        // bfs
        char chrs[4] = {'A', 'T', 'C', 'G'};
        queue<string> q;
        q.push(start);
        while (q.size()) {
            auto t = q.front(); q.pop();
            // 枚举当前单词的每个位置
            for (int i = 0; i < t.size(); i ++ ) {
                auto s = t;
                // 枚举当前单词可以变成哪个字母
                for (char c: chrs) {
                    s[i] = c;
                    if (S.count(s) && !dist.count(s)) {
                        dist[s] = dist[t] + 1;
                        if (s == end) return dist[s];
                        q.push(s);
                    }
                }
            }
        }
        return -1;
    }
};