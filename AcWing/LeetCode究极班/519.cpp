class Solution {
public:
    int r, c, k; // 行数，列数，当前剩余的总元素数量
    unordered_map<int, int> hash; // 用哈希表存所有特殊值

    Solution(int n_rows, int n_cols) {
        r = n_rows, c = n_cols;
        k = r * c;
    }
    
    vector<int> flip() {
        // 当前剩余的值是k个数，随机一个
        int x = rand() % k;
        // 如果x在哈希表中不存在的话，那么x对应的值就是x自己
        // 反之，x存的值就是在哈希表里的值
        int y = x;
        if (hash.count(x)) y = hash[x];
        // 下一步要将x存的值y删除掉，那么就是和k-1存的那个值交换一下，然后k--
        // 这里的交换也可以不实际做交换，就是把要留下的换位的数覆盖掉x这个位置就可以了
        if (!hash.count(k - 1)) hash[k - 1] = k - 1;
        hash[x] = hash[k - 1];
        hash.erase(k - 1); // 用不到了，删掉节省空间
        k -- ;
        return {y / c, y % c}; // 返回删除的值的位置下标
    }
    
    void reset() {
        k = r * c;
        hash.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */