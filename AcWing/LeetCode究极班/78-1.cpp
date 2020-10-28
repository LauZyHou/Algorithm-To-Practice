class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.emplace_back(vector<int>());
        for (int i = 0; i < nums.size(); i ++) {
            auto tmp = ans; // 这里不加引用才能拷贝一个新的
            for (auto& item : tmp) { // 这里加引用才能真的加到tmp的每一项vector<int>里去
                item.emplace_back(nums[i]);
            }
            ans.insert(ans.end(), tmp.begin(), tmp.end());
        }
        return ans;
    }
};