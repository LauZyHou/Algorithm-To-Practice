class Trie {
public:
    Trie* ch[26] = {nullptr};
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), 
            [](string& a, string&b) {return a.size()>b.size();});
        int ans = 0;
        Trie* root = new Trie();
        for(string& s : words) {
            bool isNew = false;
            Trie* p = root;
            for(int i=s.size()-1;i>=0;i--) {
                char c = s[i];
                if(p->ch[c-'a']==nullptr) {
                    p->ch[c-'a'] = new Trie();
                    isNew = true;
                }
                p = p->ch[c-'a'];
            }
            if(isNew)
                ans += s.size()+1;
        }
        return ans;
    }
};