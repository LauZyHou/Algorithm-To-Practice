class Solution {
public:
    unordered_set<string> S; // 存wordList中所有的字符串
    unordered_map<string, int> dist; // 存beginWrod走到每个字符串的最短距离
    vector<vector<string>> ans;
    vector<string> path;
    string beginWord;

    vector<vector<string>> findLadders(string _beginWord, string endWord, vector<string>& wordList) {
        beginWord = _beginWord;
        for (auto word : wordList)
            S.insert(word);
        // BFS
        queue<string> q;
        q.push(beginWord);
        while (q.size()) {
            auto t = q.front();
            q.pop();

            // 对t的每一位变成其它的字母
            string r = t;
            for (int i = 0; i < t.size(); i ++ ) {
                t = r;
                for (char j = 'a'; j <= 'z'; j ++ ) {
                    t[i] = j;
                    // 如果到这个新字符串的距离还没计算过，就写入一下
                    if (S.count(t) && dist.count(t) == 0) {
                        dist[t] = dist[r] + 1;
                        // 如果已经搜到endWord了，这一位就不用考虑变成别的字符了
                        // 但是BFS过程还要继续，因为有可能有多个路径到达endWord，到各个字符串的dist要算好
                        if (t == endWord)
                            break;
                        q.push(t);
                    }
                }
            }
        }

        // 至此，dist已经构建好了
        // 如果无法到endWord，就直接返回
        if (dist.count(endWord) == 0)
            return ans;
        // 将endWord加入到path里，从后往前搜beginWord
        path.emplace_back(endWord);
        dfs(endWord);
        return ans;
    }

    // 从t搜到beginWord
    void dfs(string t) {
        // 如果已经搜到了beginWord，翻转并加入ans
        if (t == beginWord) {
            reverse(path.begin(), path.end());
            ans.emplace_back(path);
            reverse(path.begin(), path.end());
        }
        // 否则，尝试变换t的每一位并去搜索
        else {
            string r = t;
            for (int i = 0; i < t.size(); i ++ ) {
                t = r;
                for (int j = 'a'; j <= 'z'; j ++ ) {
                    t[i] = j;
                    // 仅当变换后的字符串是合法的（这里要在dist中，因为beginWord是不在S中的
                    // 距离也要满足+1就能到r，也就是能复现BFS的路径
                    if (dist.count(t) && dist[t] + 1 == dist[r]) {
                        path.emplace_back(t);
                        dfs(t);
                        path.pop_back();
                    }
                } 
            }
        }
    }
};