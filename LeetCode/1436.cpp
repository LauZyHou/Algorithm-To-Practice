class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> st;
        unordered_set<string> use;
        for(auto& pr : paths) {
            string p1 = pr[0];
            string p2 = pr[1];
            st.insert(p1);
            st.insert(p2);
            use.insert(p1);
        }
        for(auto& s:st) {
            if(use.find(s)==use.end())
                return s;
        }
        return "";
    }
};