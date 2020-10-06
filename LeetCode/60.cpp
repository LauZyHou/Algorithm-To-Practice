class Solution {
private:
    const int FP[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};	// 全排列数
public:
    string getPermutation(int n, int k) {
        k--;
        // 取数池子
        vector<int> v(n);
        for (int i = 0; i < n; i ++)
            v[i] = i + 1;
        // 结果存放
        vector<int> ans;
        // 逆康托展开
        for (int i = n - 1; i >= 0; i --) {
            // 除以全排列数，得到商和余数
            int quotient = k / FP[i];
            int remainder = k % FP[i];
            // 商q表示池子里有q个数比它小，在池子里取第q+1个数就是这一位的值
            ans.push_back(v[quotient]);
            // 从池子里删除
            v.erase(v.begin() + quotient);
            // 下一轮用这一轮的余数
            k = remainder;
        }
        char c[ans.size() + 1];
        for (int i = 0; i < ans.size(); i ++)
            c[i] = ans[i] + '0';
        c[ans.size()] = '\0';
        return string(c);
    }
};