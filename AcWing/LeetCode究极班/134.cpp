class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        // 枚举起点
        for (int i = 0; i < n; ) {
            // 剩余油量
            int left = 0;
            // 枚举从起点走几步
            int j = 0;
            for ( ; j < n; j ++ ) {
                // 从i往后走了j步的当前位置，接下来要往下一个位置走
                int k = (i + j) % n;
                left += gas[k] - cost[k]; // 往下一个位置走会导致剩余的油量的变化
                if (left < 0) // 如果没法往下一个位置走，那么这个起点就不行，最多只能走到k
                    break;
            }
            // 如果成功走了n步那么就可以
            if (j == n)
                return i;
            // 否则，i要变成走到的位置k的后一个位置，不过k可能是比i小的，但是比i小的都算过了
            // 所以这里不对n取模，如果是走了绕回来发现不行，那么实际上就已经都不行了
            i = i + j + 1;
        }
        return -1;
    }
};