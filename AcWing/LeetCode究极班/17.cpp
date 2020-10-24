class Solution {
public:
    vector<string> ans;
    string strs[10] = {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return ans;
        dfs(digits, 0, "");
        return ans;    
    }

    void dfs(string& digits, int u, string path) {
        if (u == digits.size()) {
            ans.push_back(path);
            return;
        }
        for (auto c : strs[digits[u] - '0']) {
            dfs(digits, u + 1, path + c);
        }
    }
};