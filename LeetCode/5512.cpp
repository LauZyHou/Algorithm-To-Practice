class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& prefs, vector<vector<int>>& prs) {
        map<int, int> mp;
        for(auto& pr : prs) {
            mp[pr[0]] = pr[1];
            mp[pr[1]] = pr[0];
        }
        set<int> st;
        int ans = 0;
        for(int i=0;i<n;i++) {
            if(st.count(i))
                continue;
            // 和i配对的j
            int j = mp[i];
            auto& prefi = prefs[i];
            for(int maygood : prefi) {
                if(maygood == j)
                    break;
                // 判断maygood和i配对会不会更好
                int mj = mp[maygood];
                auto& prefmaygood = prefs[maygood];
                for(int newi : prefmaygood) {
                    if(newi == mj)
                        break;
                    if(newi == i) {
                        ans++;
                        st.insert(i);
                        if(st.count(maygood)==0) {
                            ans++;
                            st.insert(maygood);
                        }
                        goto okk;
                    }
                }
            }
            okk:
                ;
        }
        return ans;
    }
};