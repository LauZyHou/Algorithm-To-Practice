class SummaryRanges {
private:
    set<int> st;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        st.clear();
    }
    
    void addNum(int val) {
        st.insert(val);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int> > ans;
        if (!st.size())
            return ans;
        int l = *st.begin();
        int r = *st.begin();
        for (auto it = st.begin(); it != st.end(); it++) {
            if (*it > r + 1) {
                ans.push_back({l, r});
                l = *it;
            }
            r = *it;
        }
        ans.push_back({l, r});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */