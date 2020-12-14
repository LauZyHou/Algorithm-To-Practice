class Solution {
public:
    vector<string> ans; // 存所有方案

    vector<string> removeInvalidParentheses(string s) {
        // l表示当前左括号数量减去右括号数量，r表示当前要删除掉多少个右括号
        int l = 0, r = 0;
        // 从前往后枚举每一个字符
        for (auto& x: s) {
            if (x == '(') l ++ ;
            else if (x == ')') {
                // 如果当前左右括号一样多了，那么就要删除这个右括号，记录一下
                if (l == 0) r ++ ;
                // 否则记录一下这个右括号，也就是把记录左右括号数量差值的l减少1
                else l -- ;
            }
        }
        // 在计算完成之后，l就表示一共要删除的左括号的数量，r就表示一共要删除的右括号的数量
        // 字符串，当前枚举到哪个字符，当前删完之后剩余的字符串是什么，当前左括号减去右括号的数量，当前可以删除多少左括号，当前可以删除多少右括号
        dfs(s, 0, "", 0, l, r);
        return ans;
    }

    void dfs(string& s, int u, string path, int cnt, int l, int r) {
        // 如果已经枚举到了字符串结尾了
        if (u == s.size()) {
            // 如果满足当前左括号减去右括号的数量是0，就记录当前的答案
            if (!cnt) ans.push_back(path);
            return ;
        }
        // 如果当前的字符既不是左括号，也不是右括号，那么当前的字符是不能删除掉的
        if (s[u] != '(' && s[u] != ')')
            dfs(s, u + 1, path + s[u], cnt, l, r); // 把当前字符放到path里，然后从下一个字符开始搜
        // 如果当前字符是左括号
        else if (s[u] == '(') {
            // 看一下当前有多少连续的左括号
            int k = u;
            while (k < s.size() && s[k] == '(')
                k ++ ;
            // 当前连续的左括号数量就是k - u，先枚举把这些左括号都删除掉的情况
            l -= k - u;
            // 枚举要删除掉多少个左括号，即枚举删除k - u个直到删除0的情况
            for (int i = k - u; i >= 0; i -- ) {
                // 如果删掉的左括号数量没有超过l的限制
                if (l >= 0) dfs(s, k, path, cnt, l, r);
                // 根据这个循环的语义，每一轮要把左括号加回来一个
                // 每当加回来一个左括号，左括号减去右括号的差值也要加1，当前可以删除的左括号数量也要加回来1个
                path += '(';
                cnt ++, l ++ ;
            }
        }
        // 如果当前字符是右括号，也是类似的处理
        else {
            int k = u;
            while (k < s.size() && s[k] == ')')
                k ++ ;
            r -= k - u;
            for (int i = k - u; i >= 0; i -- ) {
                // 注意这里删除过多的右括号可能导致cnt小于0，所以这里要约束一下cnt也是>=0的
                if (cnt >= 0 && r >= 0) dfs(s, k, path, cnt, l, r);
                path += ')';
                cnt --, r ++ ;
            }
        }
    }
};