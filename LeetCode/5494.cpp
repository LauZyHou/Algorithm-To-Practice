class Solution {
public:
    int** mp = nullptr;
    int** dp = nullptr;
    int nn;
    const int mod = 1e9+7;

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int len = locations.size();
        this->nn = len;
        mp = new int*[len];
        for(int i=0;i<len;i++)
            mp[i] = new int[len];
        for(int i=0;i<len;i++) {
            for(int j=i;j<len;j++) {
                mp[i][j] = mp[j][i] = abs(locations[i]-locations[j]);
            }
        }
        dp = new int*[len];
        for(int i=0;i<len;i++)
            dp[i] = new int[fuel+1];
        for(int i=0;i<len;i++) {
            for(int j=0;j<fuel+1;j++) {
                dp[i][j] = -1;
            }
        }
        return dfs(start, finish, fuel);
    }

    int dfs(int s, int f, int fu) {
        if(dp[s][fu]!=-1) {
            return dp[s][fu];
        }
        int ret = (s == f) ? 1 : 0;
        // 从s到i再到f
        for(int i=0;i<nn;i++) {
            if(i!=s && mp[s][i]<=fu) {
                ret += dfs(i, f, fu-mp[s][i]);
                ret %= mod;
            }
        }
        dp[s][fu] = ret;
        return ret;
    }
};