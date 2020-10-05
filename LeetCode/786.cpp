class Solution {
private:
    int check(double x, vector<int> &v, int k, int &fa, int &fb) {
        int cnt = 0;
        //双指针统计小于x的分数个数
        for (int i = 1, j = 0; i < v.size(); i++) {
            while (j < i && v[j]*1.0/v[i] < x)
                j++;
            cnt += j;
            if (j>0 && fa*1.0/fb < v[j-1]*1.0/v[i]) // 这里不判断j>0则j-1作为索引可能溢出
                fa = v[j-1], fb = v[i];
        }
        return cnt;
    }
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& v, int k) {
        vector<int> ans(2);
        ans[0] = 0, ans[1] = 1;
        // 浮点数二分
        double l = 0, r = 1;
        while (r - l > 1e-8) {
            double mid = (l + r) / 2;
            int fa = 0, fb = 1; // check时返回最大的满足要求的分数fa/fb
            int lower = check(mid, v, k, fa, fb);
            if (lower > k) // 小于mid的分数超过k个
                r = mid;
            else if(lower < k)
                l = mid;
            else {
                ans[0] = fa;
                ans[1] = fb;
                break;
            }
        }
        return ans;
    }
};