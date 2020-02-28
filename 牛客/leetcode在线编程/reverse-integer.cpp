class Solution {
public:
    int reverse(int x) {
        int ansInt = 0;
        while(x) {
            ansInt = ansInt*10 + x%10;
            x /= 10;
        }
        return ansInt;
    }
};