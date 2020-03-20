class Solution {
public:
    int majorityElement(vector<int>& v) {
        int len = v.size();
        if(!len)
            return -1;
        int nowcnt = 0;
        int nownum = 0;
        for(int i=0;i<len;i++) {
            if(nowcnt==0) {
                nownum = v[i];
                nowcnt=1;
            } else {
                if(nownum==v[i])
                    nowcnt++;
                else
                    nowcnt--;
            }
        }
        int cnt = 0;
        for(auto& x:v) {
            if(x==nownum)
                cnt++;
        }
        return cnt*2 > len ? nownum : -1;
    }
};