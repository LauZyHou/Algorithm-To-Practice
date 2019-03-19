class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
		int j = 0;
		for(int i=0;i<len;i++){
			if(nums[i]!=val)
				nums[j++]=nums[i];//直接把不一样的存到前面就可以了
		}
		return j;
    }
};