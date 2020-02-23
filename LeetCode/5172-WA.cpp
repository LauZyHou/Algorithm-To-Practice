class Solution {
public:
    string largestMultipleOfThree(vector<int>& vs) {
        sort(vs.begin(),vs.end(),greater<int>());
        int n = vs.size();
        if(n==0)
            return "";

        int val = 0; // 用于计算前缀和
        vector<int> vsums(n); // 前缀和
        for(int i=0;i<n;i++) {
            val += vs[i];
            vsums[i] = val;
        }

        // 反向扫描前缀和可以是3的倍数的最大下标
        int maxi = n-1;
        for(;maxi>=0;maxi--) {
            if(vsums[maxi]%3==0)
                break;
        }

        // 如果无法得到答案,请返回一个空字符串,如[1,1]是没答案的而且maxi=0
        if(maxi==0 && vs[0]%3!=0)
            return "";
        
        // 去除前导0,因为从大到小排序,如果第一个就是0后面也全是0
        if(vs[0]==0)
            return "0";
        
        // 否则直接拼就行了
        char ans[maxi+1+1];
        for(int i=0;i<=maxi;i++)
            ans[i] = vs[i]+'0';
        ans[maxi+1]='\0';
        return string(ans);
    }
};