class Solution {
public:
    int majorityElement(vector<int>& v) {
        int m = 0;
        int cnt = 0;
        for(auto& x:v) {
            if(cnt==0) {
                m = x;
                cnt++;
            }
            else if(m==x)
                cnt++;
            else {
                cnt--;
            }
        }
        return m;
    }
};