class Solution {
public:
    bool canBeEqual(vector<int>& t, vector<int>& a) {
        int len = t.size();
        if(len!=a.size())
            return false;
        vector<int> v(1005, 0);
        for(int i=0;i<len;i++) {
            v[t[i]]++;
            v[a[i]]--;
        }
        for(int i=1;i<=1000;i++) {
            if(v[i])
                return false;
        }
        return true;
    }
};