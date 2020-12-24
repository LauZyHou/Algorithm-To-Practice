class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n);
        // 用栈来维护当前执行的是哪一个函数
        stack<int> stk;
        // 维护上一个事件的时间
        int last = 0;
        // 遍历所有的事件
        for (auto& log: logs) {
            // 找到第一个冒号和后一个冒号的位置
            int x = log.find(':'), y = log.substr(x + 1).find(':') + x + 1;
            // 函数的id、事件执行的时间点
            int id = stoi(log.substr(0, x)), ts = stoi(log.substr(y + 1));
            // 判断事件的类型
            if (log.substr(x + 1, y - x - 1) == "start") { // 一个新的函数的开始
                // 如果栈顶有函数，那么从栈顶函数的开始到这个函数的开始之间的时间属于栈顶的函数的独占时间
                if (stk.size()) res[stk.top()] += ts - last;
                last = ts;
                // 新函数开始，要入栈
                stk.push(id);
            }
            else { // 一个旧的函数的结束
                // 也是上个事件到这个事件的时间，不过结束事件会把当前这个1单位时间吃掉
                res[id] += ts - last + 1;
                last = ts + 1;
                // 旧函数结束，要出栈
                stk.pop();
            }
        }
        return res;
    }
};