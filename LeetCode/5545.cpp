class Solution {
private:
    int n;
    int ans;
    bool* path;

    void backtrack(int lev, vector<int>& scores, vector<int>& ages) {
        if (lev == n) {
            int res = 0;
            for (int i = 0; i < n; i ++)
                if (path[i])
                    res += scores[i];
            ans = max(ans, res);
            return ;
        }
        // 不选
        path[lev] = false;
        backtrack(lev + 1, scores, ages);

        // 选，先检查
        bool ok = true;
        for (int i = 0; i < lev; i ++)
            if (path[i] && ages[i] < ages[lev] && scores[i] > scores[lev]) {
                ok = false;
                break;
            }
            else if (path[i] && ages[i] > ages[lev] && scores[i] < scores[lev]) {
                ok = false;
                break;
            }
        if (ok) {
            path[lev] = true;
            backtrack(lev + 1, scores, ages);
        }
    }

public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        this->path = new bool[1010];
        this->ans = 0;
        this->n = ages.size();
        if (!n)
            return 0;
        backtrack(0, scores, ages);
        return ans;
    }
};