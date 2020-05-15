class Solution {
private:
    int m = 1e9+7;
    long a[2] = {0,1};
public:
    int fib(int n) {
        if(n<2)
            return a[n];
        for(int i=2;i<=n;i++) {
            long t = (a[0]+a[1])%m;
            a[0] = a[1];
            a[1] = t;
        }
        return a[1];
    }
};