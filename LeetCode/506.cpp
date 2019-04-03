class Solution {
public:
	static bool cmp(int x,int y){
		return x>y;
	}

	int findIndex(vector<int>& v,int k,int a,int b){
		int mid = (a+b)/2;
		if(v[mid]==k)
			return mid;
		else if(v[mid]>k)
			return findIndex(v,k,mid+1,b);
		return findIndex(v,k,a,mid-1);
	}

    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> v;
		v.assign(nums.begin(),nums.end());
		sort(v.begin(),v.end(),cmp);
		int nlen = nums.size();
		vector<string> ans;
		for(int i=0;i<nlen;i++){
			int pm = findIndex(v,nums[i],0,nlen-1);
			if(pm==0)
				ans.push_back("Gold Medal");
			else if(pm==1)
				ans.push_back("Silver Medal");
			else if(pm==2)
				ans.push_back("Bronze Medal");
			else
				ans.push_back(to_string(pm+1));
		}
		return ans;
    }
};