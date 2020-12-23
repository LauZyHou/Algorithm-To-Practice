class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(nums, 0);
        return ans;
    }

    void dfs(vector<int>& nums, int start) { // start表示下一个数从哪一个位置开始选
        // 这种方式在每个位置都要加答案一下
        if (path.size() >= 2) ans.push_back(path);
        // 如果已经到头了就直接返回
        if (start == nums.size()) return;
        // 枚举一下下一个数是哪个数
        // 判重，在每一层里面开一个哈希表，记录这一层已经尝试过的数字，后面就不用在尝试了
        unordered_set<int> S;
        for (int i = start; i < nums.size(); i ++ ) {
            if (path.empty() || path.back() <= nums[i]) {
                if (S.count(nums[i])) continue;
                S.insert(nums[i]);
                path.push_back(nums[i]);
                dfs(nums, i + 1);
                path.pop_back();
            }
        }
    }
};