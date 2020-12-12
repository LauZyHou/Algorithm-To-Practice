class Solution {
public:
    stack<int> num;
    stack<char> op;

    void eval() {
        int b = num.top(); num.pop();
        int a = num.top(); num.pop();
        char c = op.top(); op.pop();
        int res;
        if (c == '+') res = a + b;
        else if (c == '-') res = a - b;
        else if (c == '*') res = a * b;
        else res = a / b;
        num.push(res);
    }

    int calculate(string s) {
        // 这里要用哈希表记录一下所有运算符的优先级
        unordered_map<char, int> pr;
        pr['+'] = pr['-'] = 1;
        pr['*'] = pr['/'] = 2;
        for (int i = 0; i < s.size(); i ++ ) {
            char c = s[i];
            if (c == ' ') continue;
            if (isdigit(c)) {
                int x = 0, j = i;
                while (j < s.size() && isdigit(s[j]))
                    x = x * 10 + (s[j ++ ] - '0');
                num.push(x);
                i = j - 1;
            }
            else {
                // 栈顶的优先级大于当前运算符的优先级，就把栈顶的计算一下
                while (op.size() && pr[op.top()] >= pr[c])
                    eval();
                // 操作完成后将当前运算符加入栈顶
                op.push(c);
            }
        }
        // 最后没完成的计算一下
        while (op.size())
            eval();
        return num.top();
    }
};