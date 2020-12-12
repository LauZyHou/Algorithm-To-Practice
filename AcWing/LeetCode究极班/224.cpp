class Solution {
public:
    // a op b
    void eval(stack<int>& num, stack<char>& op) {
        auto b = num.top(); num.pop();
        auto a = num.top(); num.pop();
        auto c = op.top(); op.pop();
        int r;
        if (c == '+') r = a + b;
        else r = a - b;
        num.push(r);
    }


    int calculate(string s) {
        stack<int> num;
        stack<char> op;
        // 遍历一遍公式字符串
        for (int i = 0; i < s.size(); i ++ ) {
            // 当前字符
            auto c = s[i];
            // 跳过空格
            if (c == ' ') continue;
            // 如果是一个数的话，就把这个完整的数取出来
            if (isdigit(c)) {
                int x = 0, j = i; // j是用来取数的指针
                while (j < s.size() && isdigit(s[j]))
                    x = x * 10 + (s[j ++ ] - '0');
                i = j - 1;
                num.push(x);
            }
            // 左括号直接入栈
            else if (c == '(')
                op.push(c);
            // 右括号，要计算到左括号在符号栈顶为止
            else if (c == ')') {
                while (op.top() != '(')
                    eval(num, op); // 计算栈顶的操作
                // 计算完把左括号删除掉
                op.pop();
            }
            // 由于这题里只有加减两种运算，所以这里不需要去定义和判断优先级了
            else {
                // 只要有运算就不停运算
                while (op.size() && op.top() != '(')
                    eval(num, op);
                // 算完再把这个操作符放进来
                op.push(c);
            }
        }
        // 最后要把剩余的没有操作完的运算算完，因为之前都是遇到运算符才算的，如果是a + b + c这种那么就实际上还是没计算呢
        while (op.size())
            eval(num, op);
        return num.top();
    }
};