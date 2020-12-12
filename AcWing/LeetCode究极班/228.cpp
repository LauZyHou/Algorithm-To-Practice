class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        for (int i = 0; i < nums.size(); i ++ ) {
            int j = i + 1;
            while (j < nums.size() && nums[j] == nums[j - 1] + 1)
                j ++ ;
            if (j == i + 1)
                ans.emplace_back(to_string(nums[i]));
            else
                ans.emplace_back(to_string(nums[i]) + "->" + to_string(nums[j - 1]));
            i = j - 1;
        }
        return ans;
    }
};