class Solution {
public:
    /*
     * @param nums: a list of integers
     * @return: find a  majority number
     */
    int majorityNumber(vector<int> &nums) {
        int ans = nums[0];
		int cnt = 1;
		int len = nums.size();
		for(int i=1;i<len;i++){
			if(nums[i]==ans)
				cnt++;
			else
				cnt--;
			if(cnt<0){
				ans = nums[i];
				cnt = 1;
			}
		}
		return ans;
    }
};