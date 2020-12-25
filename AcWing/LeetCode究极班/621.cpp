class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> hash;
        int maxc = 0, cnt = 0; // 最大值和最大值出现次数
        for (auto x: tasks) {
            hash[x] ++ ;
            if (hash[x] > maxc) {
                maxc = hash[x];
                cnt = 1;
            }
            else if (hash[x] == maxc) {
                cnt ++ ;
            }
        }
        return max((maxc - 1) * (n + 1) + cnt, (int)tasks.size());
    }
};