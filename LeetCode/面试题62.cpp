class Solution {
public:
    int lastRemaining(int n, int m) {
        /*
        if(n==1)
            return 0;
        int v = lastRemaining(n-1, m);
        return (m%n + v)%n;
        */
       int ans = 0;
       for(int i=1;i<=n;i++) {
           ans = (m%i + ans)%i;
       }
       return ans;
    }
};