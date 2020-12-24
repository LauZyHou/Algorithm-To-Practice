class Solution {
public:
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }

    string fractionAddition(string expression) {
        // 先计算一下分数的个数，也就是除号的个数
        int n = 0;
        for (auto c: expression)
            if (c == '/')
                n ++ ;
        // 为了统一格式，如果最前面没有符号，在表达式最前面补上一个加号
        if (expression[0] != '-')
            expression = '+' + expression;
        // 最开始分数是0/1，偏移量（表示从第几位开始读）是0
        int a = 0, b = 1, offset = 0;
        // 分子，分母
        int c, d;
        // 符号
        char e;
        // 依次读入n个分数
        for (int i = 0; i < n; i ++ ) {
            // 从字符串按格式读入
            sscanf(expression.c_str() + offset, "%c%d/%d", &e, &c, &d);
            // 读完的地方的长度加到偏移量上
            offset += (e + to_string(c) + '/' + to_string(d)).size();
            // 计算
            if (e == '-') c = -c;
            int x = a * d + b * c;
            int y = b * d;
            // 约分一下
            int z = gcd(x, y);
            a = x / z;
            b = y / z;
        }
        // 因为题目要求分母>0，所以如果分母<0的话，分子分母全部取反
        if (b < 0) a = -a, b = -b;
        return to_string(a) + '/' + to_string(b);
    }
};