// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        // 调用两次rand7生成1-49之间的数
        int t = (rand7() - 1) * 7 + rand7(); // 1到49
        // 只有1到40保留下来
        if (t > 40) return rand10();
        int m = t % 10;
        return m == 0 ? 10 : m;
    }
};