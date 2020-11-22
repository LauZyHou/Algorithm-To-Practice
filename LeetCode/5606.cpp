class Solution {
public:
    string ans;
    
    string getSmallestString(int n, int k) {
        dfs(n, k, 0);
        return ans;
    }
    
    bool dfs(int n, int k, int u) {
        if (n == 0 && k == 0)
            return true;
        if (n <= 0 || k <= 0)
            return false;
        if (n * 26 < k)
            return false;
        for (int i = u; i < 26; i ++ ) {
            ans.push_back(i + 'a');
            if (dfs(n - 1, k - (i + 1), i))
                return true;
            ans.pop_back();
        }
        return false;
    }
};