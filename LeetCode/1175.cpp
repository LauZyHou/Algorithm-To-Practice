class Solution {
private:
    const int mod = 1e9+7;

    bool isPrime(int a) {
        if(a==1)
            return false;
        else if(a < 4)
            return true;
        for(int i=2;i*i<=a;i++)
            if(a%i==0)
                return false;
        return true;
    }

    // a <= b 求a!*b!
    int solve(int a, int b) {
        long s = 1;
        for(int i=2;i<=b;i++) {
            if(i<=a)
                s = s * i % mod * i % mod;
            else
                s = s * i % mod;
        }
        return s;
    }

public:
    int numPrimeArrangements(int n) {
        if(n<1)
            return 0;
        int pnum = 0;
        for(int i=2;i<=n;i++)
            pnum += isPrime(i);
        if(pnum <= n-pnum)
            return solve(pnum, n-pnum);
        return solve(n-pnum, pnum);
    }
};