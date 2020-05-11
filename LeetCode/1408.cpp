bool cmp (const string& a, const string& b) {
    return a.size() > b.size(); // 从大到小排序
}


class Solution {
public:
    vector<string> stringMatching(vector<string>& v) {
        vector<string> ans;
        sort(v.begin(), v.end(), cmp);
        int vlen = v.size();
        bool* ok = new bool[vlen];
        for(int i=0;i<vlen;i++)
            ok[i] = false;
        for(int i=0;i<vlen-1;i++) {
            if(ok[i]) continue;
            for(int j=i+1;j<vlen;j++) {
                if(ok[j]) continue;
                if(v[i].find(v[j])!=v[i].npos) {
                    ans.push_back(v[j]);
                    ok[j] = true;
                }
            }
        }
        return ans;
    }
};