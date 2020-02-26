class Solution {
public:
    bool isUnique(string astr) {
        int bitvec = 0;
        for(char c : astr) {
            int mask = 1 << c-'a';
            if((bitvec&mask)!=0)
                return false;
            bitvec |= mask;
        }
        return true;
    }
};