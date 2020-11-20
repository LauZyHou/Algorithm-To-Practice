class Solution {
public:
    /**
     * 
     * @param a long长整型 木棒的长度
     * @return int整型
     */
    typedef long long LL;
    LL a[60];
    
    int stick(long long b) {
        a[0] = a[1] = 1;
        for (int i = 2; i <= 60; i ++ ) {
            a[i] = a[i - 1] + a[i - 2];
        }
        LL sum = 0;
        for (int i = 0; i <= 60; i ++ ) {
            sum += a[i];
            if (sum > b)
                return i;
        }
        return -1;
    }
};