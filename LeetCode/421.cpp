class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
		int len = nums.size();
		if(len<2)
			return 0;
		int mask = 0;
		int ans = 0;
		for(int i=31;i>=0;i--) {
			mask |= (1<<i);//100..,110..,111...
			set<int> st;
			for(auto n:nums) {
				st.insert(mask&n);
			}
			//贪心地假设这一位是1
			int tmp = ans | (1<<i);
			//看看有没有两个数的前缀异或能得到它,利用三数异或的随意交换
			for(int s:st) {
				if(st.find(s^tmp)!=st.end()) {
					ans = tmp;
					break;
				}
			}
		}
		return ans;
    }
};