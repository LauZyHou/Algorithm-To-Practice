class Solution {
public:
	vector<int> v;

    Solution(vector<int>& nums) {
        this->v = nums;
    }
    
    int pick(int t) {
		int n = 0;
		int ans = -1;
        for(int i=0;i<v.size();i++) {
			if(v[i]==t) {
				n++;
				if(!(rand()%n))
					ans = i; 
			}
        }
		return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */