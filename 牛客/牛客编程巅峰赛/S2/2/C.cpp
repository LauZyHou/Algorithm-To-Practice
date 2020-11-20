class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param k int整型 表示完全k叉树的叉数k
     * @param a int整型vector 表示这棵完全k叉树的Bfs遍历序列的结点编号
     * @return long长整型
     */
    long long tree2(int k, vector<int>& a) {
        long long res = 0;
        for (int i = 1; i < a.size(); i ++ )
            res += a[i] ^ a[(i - 1) / k];
        return res;
    }
};