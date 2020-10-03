class Solution {
private:
    vector<int> s;
    int m;
public:
    bool check(int x) {
        int cnt = 0;
        int start = 1;
        int slen = s.size();
        for (int i = 2; i < slen; i++) {
            int val = s[i] - s[start-1];
            if (val > x) {
                cnt++;
                start = i;
            }
        }
        cnt++;
        return cnt <= m;
    }

    int splitArray(vector<int>& nums, int m) {
        this->m = m;
        s.clear();
        s.push_back(0);
        int sum = 0;
        int mx = INT_MIN;
        for (int n : nums) {
            if (n > mx)
                mx = n;
            sum += n;
            s.push_back(sum); // 前缀和数组，从1开始索引
        }
        int l = mx, r = sum;
        while (l < r) {
            int mid = l+r >> 1;
            if (check(mid)) { // 存在这样一种方案，最大<=mid
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }
};