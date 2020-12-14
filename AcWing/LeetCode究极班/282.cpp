typedef long long LL;

class Solution {
public:
    vector<string> ans; // 答案
    string path; // 当前的方案

    vector<string> addOperators(string num, int target) {
        // 把方案初始化成一个足够长的就可以了
        // 因为每个位置可以1.不选2.加法3.减法4.乘法
        // 所以时间复杂度是4^n，所以n是不可能太大的
        path.resize(100);
        // num，当前搜到第几位了，path里面方案的长度，a，b
        dfs(num, 0, 0, 0, 1, target);
        return ans;
    }

    void dfs(string& num, int u, int len, LL a, LL b, LL target) {
        // 已经搜完了num
        if (u == num.size()) {
            // 由于在整个表达式后面补了一个加号，这样最后a存的就应该是表达式的值
            if (a == target)
                ans.push_back(path.substr(0, len - 1)); // 注意要把最后的加号去掉
        }
        // 没有搜完num
        else {
            // 枚举当前的数是什么，也就是枚举当前的数有几位
            LL c = 0;
            for (int i = u; i < num.size(); i ++ ) {
                c = c * 10 + num[i] - '0';
                // path每次把当前的数存下来
                path[len ++ ] = num[i];
                // +，考虑下一个操作符是加法的情况
                path[len] = '+';
                dfs(num, i + 1, len + 1, a + b * c, 1, target);
                // 如果不是最后一位，才考虑减法和乘法，也就是在这里保证了最后一位一定是进行了加法运算的
                if (i + 1 < num.size()) {
                    // -
                    path[len] = '-';
                    dfs(num, i + 1, len + 1, a + b * c, -1, target);

                    // *
                    path[len] = '*';
                    dfs(num, i + 1, len + 1, a, b * c, target);
                }
                // 由于数字c不能有前导0，所以如果第一位就是0，那么0只能作为一个数，做完一轮就直接结束
                if (num[u] == '0') break;
            }
        }
    }
};