class Solution {
private:
    bool hz(int m, int n) {
        int temp;
        while(m%n>0)
        {
            temp=n;
            n=m%n;
            m=temp;
        }
        return n==1;
    }
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        if(n<=1)
            return ans;
        for(int i=2;i<=n;i++) {
            for(int j=1;j<=i-1;j++) {
                // 判断j/i互质
                if(hz(j,i))
                    ans.push_back(to_string(j)+"/"+to_string(i));
            }
        }
        return ans;
    }
};