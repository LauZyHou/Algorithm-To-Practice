class Solution
{
public:
    int rlen = 0;
    int clen = 0;
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};

    int dfs(vector<vector<int>> &vv, int a, int b)
    {
        if (a >= rlen || b >= clen || a < 0 || b < 0 || !vv[a][b])
            return 0;
        int ret = 0;
        int tmp = vv[a][b];
        vv[a][b] = 0;
        for (int i = 0; i < 4; i++)
        {
            ret = max(ret, dfs(vv, a + x[i], b + y[i]));
        }
        vv[a][b] = tmp;
        return ret + tmp;
    }

    int getMaximumGold(vector<vector<int>> &vv)
    {
        this->rlen = vv.size();
        if (!rlen)
            return 0;
        this->clen = vv[0].size();
        if (!clen)
            return 0;
        int ans = 0;
        for (int i = 0; i < rlen; i++)
        {
            for (int j = 0; j < clen; j++)
            {
                if (vv[i][j])
                {
                    ans = max(ans, dfs(vv, i, j));
                }
            }
        }
        return ans;
    }
};