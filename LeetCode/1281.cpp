class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1;
        int sum = 0;
        do {
            product *= n%10;
            sum += n%10;
            n /= 10;
        } while(n);
        return product - sum;
    }
};