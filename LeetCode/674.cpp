class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int len = nums.size();
		if(len==0)
			return 0;
		int cnt = 1;
		int max = 1;
		for(int i=1;i<len;i++){
			if(nums[i]>nums[i-1]){
				cnt++;
				continue;
			}
			if(cnt>max)
				max = cnt;
			cnt = 1;
		}
		if(cnt>max)
			max = cnt;
		return max;
    }
};