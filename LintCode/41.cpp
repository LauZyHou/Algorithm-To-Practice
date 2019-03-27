class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> &nums) {
        //DP,f(j)表示以下标为j的元素结尾的最大子数组和
		int len = nums.size();
		if(len==1)
			return nums[0];
		int ans = nums[0];
		//模拟f(j-1)和f(j)
		int fi = ans;
		int fj;
		for(int j=1;j<len;j++){
			if(fi>0)
				fj = nums[j]+fi;
			else
				fj = nums[j];
			if(fj>ans)
				ans = fj;
			fi = fj;
		}
		return ans;
    }
};