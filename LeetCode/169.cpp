class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int zs = nums[0];
		int len = nums.size();
		if(len==1)
			return zs;
		int cnt = 1;
		for(int i=1;i<len;i++)
			if(nums[i]!=zs){
				if(cnt==0){
					zs = nums[i];
					cnt = 1;
				}
				else
					cnt--;
			}
			else
				cnt++;
		return zs;
    }
};