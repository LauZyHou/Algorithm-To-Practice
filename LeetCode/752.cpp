class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> S;
        for (auto& s: deadends) S.insert(s);

        if (S.count("0000")) return -1;

        unordered_map<string, int> mp;
        mp["0000"] = 0;

        queue<string> q;
        q.push("0000");

        while (q.size()) {
            auto t = q.front();
            q.pop();
            if (t == target)
                break;
            for (int i = 0; i < 4; i ++ ) {
                auto r = t;
                int v = r[i] - '0';
                r[i] = (v + 1) % 10 + '0';
                if (!mp.count(r) && !S.count(r)) {
                    mp[r] = mp[t] + 1;
                    q.push(r);
                }
                r[i] = (v - 1 + 10) % 10 + '0';
                if (!mp.count(r) && !S.count(r)) {
                    mp[r] = mp[t] + 1;
                    q.push(r);
                }
            }
        }

        if (mp.count(target))
            return mp[target];
        return -1;
    }
};