class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
		int i = 0;
		int j = 0;
		for(;j<len;j++){
			if(nums[j]!=0)
				swap(nums[j],nums[i++]);
		}
    }
};