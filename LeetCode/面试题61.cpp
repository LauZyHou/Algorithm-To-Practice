class Solution {
public:
    bool isStraight(vector<int>& v) {
        int mx = INT_MIN;
        int mn = INT_MAX;
        unordered_set<int> st;
        for(int r : v){
            if(!r)
                continue;
            if(r > mx)
                mx = r;
            if(r < mn)
                mn = r;
            if(st.count(r))
                return false;
            st.insert(r);
        }
        return mx - mn < 5 || st.size()==0;
    }
};