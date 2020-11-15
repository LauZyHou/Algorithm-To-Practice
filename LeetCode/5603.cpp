class Solution {
public:
    bool closeStrings(string w1, string w2) {
        int n = w1.size(), m = w2.size();
        if (n != m) return false;
        
        vector<int> a(26);
        sort(w1.begin(), w1.end());
        sort(w2.begin(), w2.end());
        if (w1 == w2) return true;
        
        vector<int> a1(26), a2(26);
        for (auto c : w1) {
            a1[c - 'a'] ++ ;
        }
        for (auto c : w2) {
            a2[c - 'a'] ++ ;
        }
        
        for (int i = 0; i < 26; i ++ ) {
            if (a1[i] && !a2[i] || a2[i] && !a1[i])
                return false;
        }
        
        sort(a1.begin(), a1.end());
        sort(a2.begin(), a2.end());
        for (int i = 0; i < 26; i ++ )
            if (a1[i] != a2[i])
                return false;
        return true;
    }
};