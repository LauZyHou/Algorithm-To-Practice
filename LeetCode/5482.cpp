class Solution {
public:
    int to[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    int m,n;

    // 用来杀死没用的点
    void dfs2(vector<vector<char>>& vv, int a, int b, char c) {
        vv[a][b] = '*';
        for(int i=0;i<4;i++) {
            int na = a+to[i][0];
            int nb = b+to[i][1];
            if(na<0 || na>=m || nb<0 || nb>=n)
                continue;
            if(vv[na][nb]==c)
                dfs2(vv, na, nb, c);
        }
    }

    // 用来查找
    bool dfs(vector<vector<char>>& vv, int a, int b, int fa, int fb) {
        vv[a][b] = vv[a][b]-'a'+'A';
        bool ret = false;
        for(int i=0;i<4;i++) {
            int na = a+to[i][0];
            int nb = b+to[i][1];
            if(na<0 || na>=m || nb<0 || nb>=n)
                continue;
            if(na==fa && nb==fb)
                continue;
            if(vv[na][nb]==vv[a][b])
                return true;
            if(vv[na][nb]==vv[a][b]-'A'+'a')
                ret |= dfs(vv, na, nb, a, b);
            if(ret)
                return true;
        }
        return ret;
    }

    bool containsCycle(vector<vector<char>>& vv) {
        m = vv.size();
        n = vv[0].size();
        if(m*n<4)
            return false;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(vv[i][j]>'z' || vv[i][j]<'a')
                    continue;
                if(dfs(vv, i, j, i, j))
                    return true;
                dfs2(vv, i, j, vv[i][j]);
            }
        }
        return false;
    }
};