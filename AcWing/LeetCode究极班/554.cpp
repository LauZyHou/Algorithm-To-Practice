class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int cnt = 0; // 最多出现的缝隙数量
        unordered_map<int, int> hash; // 哈希表存所有的缝隙
        // 对于每一行
        for (auto& line: wall) {
            // 统计一下这一行里面所有的缝隙，其实也就是计算前缀和
            // 注意一下最后一个缝隙是最后一条边，不能算
            for (int i = 0, s = 0; i < line.size() - 1; i ++ ) {
                s += line[i];
                hash[s] ++ ;
                cnt = max(cnt, hash[s]);
            }
        }
        return wall.size() - cnt;
    }
};