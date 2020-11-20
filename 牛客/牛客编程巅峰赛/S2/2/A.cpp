class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 返回牛牛能吃到的最多糖果数
     * @param n long长整型 
     * @param k long长整型 
     * @return long长整型
     */
    long long Maximumcandies(long long n, long long k) {
        return (k - n) / (n + 1);
    }
};