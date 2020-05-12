class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if(s1.size()!=s2.size())
            return false;
        s1.append(s1);
        return s1.find(s2)!=s1.npos;
    }
};