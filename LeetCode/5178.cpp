class Solution {
private:
    int sum = 0;// 顺便求和
    bool factorIs4(int n) {
        if(n<2)
            return false;
        int cnt = 0;
        int p = sqrt(n);
        // 对于一个平方数不可能是4因数
        if(p*p==n)
            return false;
        sum = 1+n;
        for(int i=2;i<=p;i++) {
            if(n%i==0) {
                sum += i+n/i;
                cnt+=2;
            }
            if(cnt>2)
                return false;
        }
        return cnt==2;
    }
public:
    int sumFourDivisors(vector<int>& v) {
        int ans = 0;
        for(auto&x:v) {
            if(factorIs4(x))
                ans+=sum;
        }
        return ans;
    }
};