class Solution {
private:
    int len;
    string s;
    vector<string> ans;

    void backtrack(int i) {
        if(i==len) {
            ans.push_back(string(s));
        }
        else {
            for(int j=i;j<len;j++) {
                swap(s[i], s[j]);
                backtrack(i+1);
                swap(s[i], s[j]);
            }
        }
    }

public:
    vector<string> permutation(string _s) {
        s = _s;
        len = s.size();
        backtrack(0);
        return ans;
    }
};