class Solution {
public:
    int maximumProduct(vector<int>& nums) {
		//考虑理想情况,三个最大正数相乘/两个最小负数乘以最大正数
		//考虑正数不够/负数不够的情况,比如-2,-1,1,2,符合-2*-1*2
		//如果没正数,如-4,-3,-2,-1,这时候要-3*-2*-1最小
		//如果没负数,如1,2,3,4,这时候要2*3*4
		//所以一定是max(最大三个数,最小两个数*最大一个数)
		sort(nums.begin(),nums.end());
		int len = nums.size();
		return max(nums[len-1]*nums[len-2]*nums[len-3], nums[0]*nums[1]*nums[len-1]);
    }
};