class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& v) {
        int len = v.size();
        vector<int> ans;
        vector<int> cnt(n+1, 0);
        int mx = 0;
        for(int i=0;i<len-1;i++) {
            int f = v[i]; // from
            int t = v[i+1]; // to
            for(int j=f;;j++) {
                if(j>n)
                    j-=n;
                if(j==t)
                    break;
                cnt[j]++;
                if(cnt[j]>mx)
                    mx = cnt[j];
            }
        }
        cnt[v[len-1]]++;
        if(cnt[v[len-1]]>mx)
            mx = cnt[v[len-1]];
        for(int i=1;i<=n;i++) {
            if(cnt[i]==mx)
                ans.push_back(i);
        }
        return ans;
    }
};