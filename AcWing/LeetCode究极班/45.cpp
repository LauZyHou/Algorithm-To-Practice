class Solution {
public:
    int jump(vector<int>& nums) {
        // f[i]表示从起点跳到i最短跳几步，求出f[n - 1]就是答案
        // f[i]直觉上是单调连续的，不会某个数跳3步可以到，然后后面相邻的就突然要跳5步了
        // 就是f[i]大概就是0, 0, 0, 1, 1, 2, 2, 3, 4, 4, 5, 5, 5, 6, 7, 7... 这样

        int n = nums.size();
        vector<int> f(n);
        
        for (int i = 1, j = 0; i < n; i ++) {
            // 找到刚能跳到i位置后面位置的j，那个位置的f值和f[i]是一样的，都是f[j]+1
            while (j + nums[j] < i)
                j ++;
            f[i] = f[j] + 1;
        }
        
        return f[n - 1];
    }
};