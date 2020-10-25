const int N = 1e6 + 10;

class Solution {
private:
    char stk[N];
    int cnt;

    bool match(char a, char b) {
        return a == '(' && b == ')' ||
            a == '[' && b == ']' ||
            a == '{' && b == '}';
    }
public:
    bool isValid(string s) {
        cnt = 0;
        for (auto c : s) {
            if (c == '{' || c == '[' || c == '(')
                stk[++ cnt] = c;
            else {
                if (cnt == 0)
                    return false;
                char r = stk[cnt --];
                if (!match(r, c))
                    return false;
            }
        }
        return cnt == 0;
    }
};