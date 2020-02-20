class Solution {
public:
    vector<int> printNumbers(int n) {
        int end=1, cnt=10;
        // 快速幂求end=10^n
        while(n) {
            if(n&1)
                end*=cnt;
            cnt*=cnt;
            n>>=1;
        }
        vector<int> ans(end-1); // 先把空间开好,这样比push_back快
        for(int i=1;i<end;i++){
            ans[i-1] = i;
        }
        return ans;
    }
};