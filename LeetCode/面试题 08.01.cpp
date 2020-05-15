class Solution {
private:
    int m = 1e9+7;
    long a[3] = {1,1,2};
public:
    int waysToStep(int n) {
        if(n<3)
            return a[n];
        for(int i=3;i<=n;i++) {
            long t = (a[0] + a[1] + a[2])%m;
            a[0] = a[1];
            a[1] = a[2];
            a[2] = t;
        }
        return a[2];
    }
};