class Solution {
private:
    int *ne = nullptr;
    // 处理s上从l到r的二进制序列，保证s[l..r]是一个合法的特殊二进制序列
    void arrange(string &s, int l, int r) {
        if (l > r) 
            return ;
        multiset<string> mts;
        // 每次去掉子串里最外层的括号再处理里面，因为外面一定包了一个括号没什么好排序的
        // ( () ((())) )
        for (int i = l; i < r; i = ne[i] + 1) { // i每次移动到下一个子串开头位置
            arrange(s, i + 1, ne[i] - 1);
            // 处理完整个扔到multiset里排字典序
            // 用set也可以排字典序，但是set会去重，这里字符串可能是重复的
            mts.insert(s.substr(i, ne[i] - i + 1));
        }
        // 因为结果要字典序最大的串s，而multiset里是按从小到大放置的每个子串
        // 所以直接反向从multiset里取就可以了
        int p = l;
        for (auto it = mts.rbegin(); it != mts.rend(); it ++)
            for (char c : *it)
                s[p] = c, p ++;
    }
public:
    string makeLargestSpecial(string s) {
        // 0 1 2 3 4 5
        // ( ( ) ) ( )
        // 1 1 0 0 1 0
        int n = s.size();
        // ne用于配对
        // ne[0] = 3, ne[1] = 2, ne[4] = 5
        ne = new int[n];
        // 计算ne数组
        stack<int> st;
        for (int i = 0; i < n; i ++) {
            if (s[i] == '1') {
                st.push(i);
            }
            else {
                int tp = st.top();
                st.pop();
                ne[tp] = i;
            }
        }
        // 处理整个二进制序列
        arrange(s, 0, n - 1);
        return s;
    }
};