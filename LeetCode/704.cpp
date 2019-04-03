class Solution {
public:
	int bs(vector<int>& v,int t,int a,int b){
		if(a>b)
			return -1;
		int mid = (a+b)/2;
		if(v[mid]==t)
			return mid;
		else if(v[mid]>t)
			return bs(v,t,a,mid-1);
		return bs(v,t,mid+1,b);
	}

    int search(vector<int>& nums, int target) {
		return bs(nums,target,0,nums.size()-1);
	}
};