class Solution {
public:
    vector<int> finalPrices(vector<int>& v) {
        stack<int> st; // 单调栈里存下标
        int len = v.size();
        for(int j=0;j<len;j++) {
            while(st.size()>0 && v[st.top()]>=v[j]) {
                int i = st.top();
                st.pop();
                v[i] -= v[j];
            }
            st.push(j);
        }
        return v;
    }
};