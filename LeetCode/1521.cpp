class Solution {
public:
    int closestToTarget(vector<int>& v, int t) {
        set<int> st;
        st.insert(v[0]); // r = 0
        int ans = abs(v[0] - t);
        for (int r = 1; r < v.size(); r ++) {
            set<int> stNew;
            stNew.insert(v[r]);
            ans = min(ans, abs(v[r] - t));
            for (int s : st) {
                int val = s & v[r];
                stNew.insert(val);
                ans = min(ans, abs(val - t));
            }
            st = stNew;
        }
        return ans;
    }
};