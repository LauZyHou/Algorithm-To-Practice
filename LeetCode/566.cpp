class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int rs = nums.size();
		if(rs==0)
			return nums;
		int cs = nums[0].size();
		if(cs==0)
			return nums;
		if(cs*rs != r*c)
			return nums;
		
		vector<vector<int>> ans;
		int cnt = 0;
		vector<int> vc;
		
		for(int is=0;is<rs;is++)
			for(int js=0;js<cs;js++){					
				vc.push_back(nums[is][js]);
				if(cnt%c==c-1){
					ans.push_back(vc);
					vector<int>().swap(vc);//清空
				}
				cnt++;
			}
		return ans;
    }
};