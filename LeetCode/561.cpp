class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
		int ans = 0;
		int len = nums.size();
		for(int i=0;i<len;i+=2){
			ans += nums[i];
		}
		return ans;
    }
};