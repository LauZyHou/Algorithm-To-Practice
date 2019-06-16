class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int len = nums.size();
		vector<int> ans;
		/*
		for(int i=0;i<len;i++) {
			int now = abs(nums[i]);
			nums[now-1] = -nums[now-1];
		}
		for(int i=0;i<len;i++) {
			if(nums[i]>0)
				ans.push_back(i+1);
		}
		return ans;
		*/
		//上面这种做法,如果某个元素没出现过,那那个位置元素也是正数(没变过)
		//所以要在第一次循环中,当发现已经是负数时,就记录下来这个元素出现了两次
		for(int i=0;i<len;i++) {
			int a = abs(nums[i]);
			if(nums[a-1]>0)
				nums[a-1] = -nums[a-1];
			else//不可能是0,不是正数就一定是负数
				ans.push_back(a);
		}
		return ans;
    }
};