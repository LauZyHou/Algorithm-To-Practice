class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
		int t = 0;
		int len = nums.size();
		for(int i=0;i<len;i++){
			if(nums[i]==0){
				if(t>ans)
					ans = t;
				t = 0;
			}
			else{
				t++;
			}
		}
		if(t>ans)
			ans = t;
		return ans;
    }
};