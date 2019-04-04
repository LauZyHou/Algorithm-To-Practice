class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //将所有正数作为数组下标，置对应数组值为负的(小心变负又变正就不对了)
		//那么，仍为正数的位置即为（未出现过）消失的数字
		vector<int> ans;
		for(auto a : nums){
			int t = abs(a);
			if(nums[t-1]>0)
				nums[t-1] = -nums[t-1];
		}
		int len = nums.size();
		for(int i=0;i<len;i++){
			if(nums[i]>0)
				ans.push_back(i+1);
		}
		return ans;
    }
};