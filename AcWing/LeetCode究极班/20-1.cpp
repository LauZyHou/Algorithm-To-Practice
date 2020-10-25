class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char c : s) {
            if (c == '{' || c == '[' || c == '(')
                stk.push(c);
            else {
                if (stk.size() && abs(stk.top() - c) <= 2)
                    stk.pop();
                else
                    return false;
            }
        }
        return stk.empty();
    }
};