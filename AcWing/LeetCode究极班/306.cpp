class Solution {
public:

    string add(string x, string y) {
        // 把两个数变成逆序的vector
        vector<int> A, B;
        for (int i = x.size() - 1; i >= 0; i -- ) A.emplace_back(x[i] - '0');
        for (int i = y.size() - 1; i >= 0; i -- ) B.emplace_back(y[i] - '0');
        // 计算答案
        vector<int> C;
        for (int i = 0, t = 0; i < A.size() || i < B.size() || t; i ++ ) {
            if (i < A.size()) t += A[i];
            if (i < B.size()) t += B[i];
            C.emplace_back(t % 10);
            t /= 10;
        }
        // 把答案变成字符串返回
        string z;
        for (int i = C.size() - 1; i >= 0; i -- )
            z += to_string(C[i]);
        return z;
    }

    bool isAdditiveNumber(string num) {
        // 先枚举第一个数的结尾位置
        for (int i = 0; i < num.size(); i ++ )
            // 再枚举第二个数的结尾位置
            for (int j = i + 1; j + 1 < num.size(); j ++ ) { // 由于要保证串中至少要有三个数，所以j + 1 < nums.size()
                // 判断一下当前这种情况合法不合法
                // a表示第一个数的起始位置之前的一个位置，b表示第一个数的结束位置
                // b+1表示第二个数的起始位置，c表示第二个数的结束位置
                int a = -1, b = i, c = j;
                while (true) {
                    // 先判断一下有没有前导0，如果两个数在计算过程中有一个出现前导0那么都是不合法的
                    if (b - a > 1 && num[a + 1] == '0' || c - b > 1 && num[b + 1] == '0') break;
                    // x表示第一个数
                    auto x = num.substr(a + 1, b - a);
                    // y表示第二个数
                    auto y = num.substr(b + 1, c - b);
                    // 高精度加法
                    auto z = add(x, y);
                    // 判断一下z是不是和从c+1开始的一段是匹配的，如果不匹配就说明选的不对
                    if (num.substr(c + 1, z.size()) != z) break;
                    // 更新一下a,b,c三个游标的位置
                    a = b, b = c, c += z.size();
                    // 如果恰好匹配完了最后一个位置，说明找到了一个解
                    if (c + 1 == num.size()) return true;
                }
            }
        return false;
    }
};