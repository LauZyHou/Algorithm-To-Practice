class Solution {
public:
    vector<string> ans;
    vector<int> f;
    int n;
    unordered_set<string> hash;

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        
        for (auto& word: wordDict)
            hash.insert(word);

        f.resize(n + 1);
        f[n] = true;

        for (int j = n; ~j; j -- ) {
            if (f[j]) {
                for (int i = 0; i < j; i ++ ) {
                    if (hash.count(s.substr(i, j - i)))
                        f[i] = true;
                }
            }
        }

        dfs(s, 0, "");
        return ans;
    }

    void dfs(string& s, int u, string path) {
        if (u == n) {
            path.pop_back();
            ans.emplace_back(path);
        }
        else {
            // u..j
            for (int j = u; j < n; j ++ ) {
                string t = s.substr(u, j - u + 1);
                if (f[j + 1] && hash.count(t)) {
                    dfs(s, j + 1, path + t + ' ');
                }
            }
        }
    }
};