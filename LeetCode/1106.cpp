class Solution {
public:
    bool parseBoolExpr(string expr) {
        int n = expr.size();
        stack<bool> val;
        stack<char> symb;
        for (char c : expr) {
            switch(c) {
                case 'f':
                    val.push(false);
                    break;
                case 't':
                    val.push(true);
                    break;
                case '!':
                case '&':
                case '|':
                case ',':
                    symb.push(c);
                    break;
                case ')':
                {
                    // 计算逗号数量
                    int sepnum = -1;
                    char sy;
                    do {
                        sy = symb.top();
                        symb.pop();
                        sepnum ++;
                    } while (sy == ',');
                    switch (sy) {
                        case '!':
                        {
                            bool v = val.top();
                            val.pop();
                            v = !v;
                            val.push(v);
                            break;
                        }
                        case '&':
                        {
                            bool v = val.top();
                            val.pop();
                            while (sepnum -- ) {
                                v &= val.top();
                                val.pop();
                            }
                            val.push(v);
                            break;
                        }
                        case '|':
                        {
                            bool v = val.top();
                            val.pop();
                            while (sepnum -- ) {
                                v |= val.top();
                                val.pop();
                            }
                            val.push(v);
                            break;
                        }
                    }
                    break;
                }
            }
        }
        return val.top();
    }
};