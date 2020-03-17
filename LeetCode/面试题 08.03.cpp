class Solution {
public:
    int findMagicIndex(vector<int>& v) {
        for(int i=0;i<v.size();i++) {
            if(v[i]==i)
                return i;
        }
        return -1;
    }
};