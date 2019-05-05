class Solution {
public:
    int dominantIndex(vector<int>& nums) {
		int len = nums.size();
		int it = nums[0];
		int idx = 0;
		bool ok = true;
		for(int i=1;i<len;i++){
			int now = nums[i];
			if(now<it && now*2>it)
				ok = false;
			else if(now>it) {
				ok = it*2<=now;
				it = now;
				idx = i;
			}
		}
		return ok?idx:-1;
    }
};