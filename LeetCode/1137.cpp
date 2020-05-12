class Solution {
private:
    int val[3] = {0,1,1};
public:
    int tribonacci(int n) {
        if(n < 3)
            return val[n];
        int k = 2;
        while(k<n) {
            int t = val[0] + val[1] + val[2];
            val[0] = val[1];
            val[1] = val[2];
            val[2] = t;
            k++;
        }
        return val[2];
    }
};