class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> st;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ans.clear();
        path = vector<int>(nums.size());
        st = vector<bool>(nums.size());

        sort(nums.begin(), nums.end());
        dfs(nums, 0);

        return ans;
    }

    void dfs(vector<int>& nums, int u) {
        if (u == nums.size()) {
            ans.emplace_back(path);
            return ;
        }

        for (int i = 0; i < nums.size(); i ++) {
            // 排序好后，一定从前往后依次取一样的数，如果上一个一样的数还没取过，则不能用这个数
            if (i && nums[i] == nums[i - 1] && !st[i - 1])
                continue;
            if (!st[i]) {
                path[u] = nums[i];
                st[i] = true;
                dfs(nums, u + 1);
                st[i] = false;
            }
        }
    }
};