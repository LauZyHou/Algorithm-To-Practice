class Solution {
private:
    int ans = 0;
public:
    int sumNums(int n) {
        bool b = n > 1 && sumNums(n-1);
        ans += n;
        return ans;
    }
};