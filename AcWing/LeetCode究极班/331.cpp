class Solution {
public:
    int k; // 遍历用的指针
    string s;

    bool isValidSerialization(string preorder) {
        k = 0;
        s = preorder + ','; // 由于每次都以逗号作为一个结点的结尾判断，所以最后面统一加上一个逗号
        // 构造一下，构造过程中没有问题，再判断一下是不是s串中没有多余的元素，也就是k能走完
        if (!dfs()) return false;
        return k == s.size();
    }

    bool dfs() {
        // 递归下去一定是这个点有东西，如果发现应该有东西但是字符串没有了那就不合法
        if (k >= s.size()) return false;
        // 当前遇到空，那么就不用往下遍历子树了
        if (s[k] == '#') {
            k += 2;
            return true;
        }
        // 先把逗号前面的部分都过滤掉（不关心结点的具体值）
        while (s[k] != ',') k ++ ;
        // 再把逗号过滤掉
        k ++ ;
        // 再依次遍历左子树和右子树
        return dfs() && dfs();
    }
};