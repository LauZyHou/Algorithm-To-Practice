class Solution {
public:
    int busyStudent(vector<int>& s, vector<int>& e, int q) {
        int ans = 0;
        int len = s.size();
        for(int i=0;i<len;i++) {
            if(s[i]<=q && q<=e[i])
                ans++;
        }
        return ans;
    }
};