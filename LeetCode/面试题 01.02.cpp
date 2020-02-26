class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        int asccii[128] = {0};
        int len1 = s1.size();
        int len2 = s2.size();
        if(len1!=len2)
            return false;
        for(int i=0;i<len1;i++) {
            asccii[s1[i]]++;
            asccii[s2[i]]--;
        }
        for(int i=0;i<128;i++)
            if(asccii[i]!=0)
                return false;
        return true;
    }
};