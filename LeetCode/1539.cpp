class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> st;
        for (auto a: arr)
            st.insert(a);
        int i;
        for (i = 1; k ; i ++ ) {
            if (!st.count(i)) k -- ;
            if (k == 0) break;
        }
        return i;
    }
};