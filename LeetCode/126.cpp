class Solution {
public:
    unordered_set<string> S;
    unordered_map<string, int> dist;
    vector<vector<string>> ans;
    vector<string> path;
    string ed;

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        ed = endWord;
        path.emplace_back(beginWord);

        for (auto &s: wordList)
            S.insert(s);
        dist[beginWord] = 0;

        queue<string> q;
        q.push(beginWord);
        while (q.size()) {
            string t = q.front();
            q.pop();
            for (int i = 0; i < t.size(); i ++ ) {
                auto r = t;
                for (char c = 'a'; c <= 'z'; c ++ ) {
                    r[i] = c;
                    if (S.count(r) && !dist.count(r)) {
                        dist[r] = dist[t] + 1;
                        q.push(r);
                        if (r == endWord)
                            break;
                    }
                }
            }
        }

        if (!dist.count(endWord)) return ans;
        dfs(beginWord);
        return ans;
    }

    void dfs(string s) {
        if (s == ed) {
            ans.push_back(path);
            return ;
        }
        for (int i = 0; i < s.size(); i ++ ) {
            auto r = s;
            for (char c = 'a'; c <= 'z'; c ++ ) {
                r[i] = c;
                if (dist.count(r) && dist[r] == dist[s] + 1) {
                    path.emplace_back(r);
                    dfs(r);
                    path.pop_back();
                }
            }
        }
    }
};