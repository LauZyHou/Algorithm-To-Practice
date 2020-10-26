class Solution {
public:
    int longestValidParentheses(string s) {
        // 合法的括号序列满足：
        // 1. '('和')'数量相等
        // 2. 任意前缀当中'('数量>=')'数量
        // 以所有')'数量>'('数量的位置作为分割点，则合法的括号序列不会跨越分割点
        stack<int> stk;

        int res = 0;
        for (int i = 0, start = -1; i < s.size(); i ++) {
            if (s[i] == '(')
                stk.push(i);
            // 右括号
            else {
                // 如果不为空，可以出栈
                if (stk.size()) {
                    stk.pop();
                    // 出栈后还不为空，则匹配的是栈顶'('之后的位置
                    if (stk.size()) {
                        res = max(res, i -(stk.top() + 1) + 1);
                    }
                    // 出栈后为空，则匹配的是从start开始的位置
                    else {
                        res = max(res, i - start); // start总是记录区间的前一个位置，这样就不用减掉在+1了
                    }
                }
                // 如果栈为空，说明这个区间的都匹配完了，这个右括号没人能匹配，只能作为下一个区间的开始位置的前一位置
                else {
                    start = i;
                }
            }
        }

        return res;
    }
};