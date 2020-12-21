class Solution {
public:
    int lengthLongestPath(string input) {
        stack<int> stk; // 维护当前路径的栈，栈里存的int值是路径上字符的长度，栈的元素个数就是当前的层数
        int res = 0;
        // sum存的是当前路径上所有元素的长度，其实也就是栈里所有数的加和，这里放在外面维护一下比较快
        for (int i = 0, sum = 0; i < input.size(); i ++ ) {
            // 看一下当前是在第几层，也就是数一下这行里开头有几个制表符
            int k = 0;
            while (i < input.size() && input[i] == '\t') i ++ , k ++ ;
            // 如果k比较小，就要一直退栈
            while (k < stk.size()) sum -= stk.top(), stk.pop();
            // 把当前的点找出来
            int j = i;
            while (j < input.size() && input[j] != '\n') j ++ ;
            string now = input.substr(i, j - i);
            stk.push(j - i);
            sum += j - i;
            // 更新答案时候要判断一下，如果当前点是文件的时候才统计，如果是文件夹就不统计了
            if (now.find('.') != string::npos)
                res = max(res, sum + (int)stk.size() - 1); // 这里加stk.size()-1是因为文件和文件之间有斜杠
            i = j; // 记得更新已经搜完的位置
        }
        return res;
    }
};