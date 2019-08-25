class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int big1 = -1, big2 = -1, ans = -1;
		int len = nums.size();
		for(int i=0;i<len;i++) {
			if(nums[i]>=big1) {//样例松,这里写>也能过
				big2 = big1;
				big1 = nums[i];
				ans = i;
			} else if(nums[i]>big2) {
				big2 = nums[i];
			}
		}
		return big1>=2*big2 ? ans : -1;
    }
};