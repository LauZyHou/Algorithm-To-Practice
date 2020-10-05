class Solution {
public:
    vector<int> threeEqualParts(vector<int>& v) {
        vector<int> ans(2);
        ans[0] = ans[1] = -1;

        int len = v.size();
        if (len < 3)
            return ans;

        int sum = 0;
        for (int val : v)
            sum += val;
        if (sum % 3)
            return ans;
        else if (sum == 0) {
            ans[0] = 0;
            ans[1] = 2;
            return ans;
        }
        int num = sum / 3; // 1的个数

        int a1, b1, a2, b2, a3, b3; // 用边界1分隔的最小区间
        int cnt = 0;
        for (int i = 0; i < len; i++) {
            if (v[i] == 1) {
                cnt++;
                if (cnt == 1) a1 = i;
                if (cnt == num) b1 = i;
                if (cnt == num + 1) a2 = i;
                if (cnt == 2 * num) b2 = i;
                if (cnt == 2 * num + 1) a3 = i;
                if (cnt == 3 * num) b3 = i;
            }
        }
        // 比较这些区间是一样的
        if (b1 - a1 != b2 - a2 || b2 - a2 != b3 - a3)
            return ans;
        int gap = b1 - a1;
        for (int i = 0; i <= gap; i ++) {
            int v1 = v[a1+gap];
            int v2 = v[a2+gap];
            int v3 = v[a3+gap];
            if (v1 != v2 || v2 != v3)
                return ans;
        }
        // 计算末尾0是足够用的
        int tailzero = v.size() - 1 - b3;
        if (a2 - b1 - 1 < tailzero || a3 - b2 - 1 < tailzero)
            return ans;
        // 得到答案
        ans[0] = b1 + tailzero;
        ans[1] = b2 + tailzero + 1;
        return ans;
    }
};