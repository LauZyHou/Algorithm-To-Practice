class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (auto& s: tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int b = stk.top(); stk.pop(); // 注意a运算b，先弹出来的是b
                int a = stk.top(); stk.pop();
                if (s == "+")
                    a += b;
                else if (s == "-")
                    a -= b;
                else if (s == "*")
                    a *= b;
                else
                    a /= b;
                stk.push(a);
            }
            else {
                stk.push(stoi(s));
            }
        }
        return stk.top();
    }
};