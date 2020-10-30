class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> S;
        for (auto word : wordList)
            S.insert(word);
        
        unordered_map<string, int> dist;
        dist[beginWord] = 0;

        queue<string> q;
        q.push(beginWord);

        while (q.size()) {
            auto t = q.front();
            q.pop();
            auto r = t;
            for (int i = 0; i < t.size(); i ++ ) {
                t = r;
                for (char j = 'a'; j <= 'z'; j ++ ) {
                    t[i] = j;
                    if (S.count(t) && !dist.count(t)) {
                        dist[t] = dist[r] + 1;
                        q.push(t);
                    }
                }
            }
        }

        if (dist.count(endWord))
            return dist[endWord] + 1;
        return 0;
    }
};