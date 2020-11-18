class Solution {
public:
    int get(int x) {
        int res = 0;
        while (x) {
            res += (x % 10) * (x % 10);
            x /= 10; 
        }
        return res;
    }
    bool isHappy(int n) {
        auto slow = n, fast = get(n);
        while (fast != slow) {
            fast = get(get(fast));
            slow = get(slow);
        }
        return slow == 1;
    }
};