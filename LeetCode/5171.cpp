class Solution {
public:
    vector<int> closestDivisors(int num) {
        int n1 = num+1;
        int n2 = num+2;
        // 计算n1的最优
        int m1 = sqrt(n1);
        while(n1%m1!=0) {
            m1--;
        }
        // 计算n2的最优
        int m2 = sqrt(n2);
        while(n2%m2!=0) {
            m2--;
        }
        vector<int> ans(2);
        if (n1/m1-m1 < n2/m2-m2) {
            ans[0] = n1/m1;
            ans[1] = m1;
        } else {
            ans[0] = n2/m2;
            ans[1] = m2;
        }
        return ans;
    }
};