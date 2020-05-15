class Solution {
public:
    bool checkIfExist(vector<int>& v) {
        unordered_map<int,bool> mp;
        for(int r:v) {
            if(mp[r*2] || !(r&1) && mp[r/2])
                return true;
            mp[r] = true;
        }
        return false;
    }
};