class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& v) {
        int len = v.size();
        for(int i=0;i<len-2;i++) {
            if((v[i]&1) && (v[i+1]&1) && (v[i+2]&1))
                return true;
        }
        return false;
    }
};