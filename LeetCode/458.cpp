class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int state = minutesToTest / minutesToDie + 1;
        // 使得pow(state, ans) >= buckets，求log以state为底buckets的对数
        return ceil(log(buckets) / log(state));
    }
};