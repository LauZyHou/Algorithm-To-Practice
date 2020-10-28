class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return ans;
    }

    void dfs(vector<int>& nums, int u) {
        if (u == nums.size()) {
            ans.emplace_back(path);
            return ;
        }

        int k = u + 1;
        while (k < nums.size() && nums[k] == nums[u])
            k ++;
        // 至此，这个数出现了k - u次，k指向的是后面第一个和nums[u]不同的数
        
        for (int i = 0; i <= k - u; i ++) {
            dfs(nums, k);
            path.emplace_back(nums[u]);
        }

        // 恢复现场
        for (int i = 0; i <= k - u; i ++) {
            path.pop_back();
        }
    }
};