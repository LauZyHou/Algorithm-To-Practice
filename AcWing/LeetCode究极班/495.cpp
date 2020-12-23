class Solution {
public:
    int findPoisonedDuration(vector<int>& w, int duration) {
        int res = 0;
        for (int i = 1; i < w.size(); i ++ ) res += min(w[i] - w[i - 1], duration);
        if (w.size()) res += duration; // 如果至少攻击了一次，那么就要把最后一个点引起的攻击时间加上
        return res;
    }
};