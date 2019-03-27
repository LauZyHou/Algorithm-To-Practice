class Solution {
public:
    /**
     * @param nums: An integer array
     * @return: nothing
     */
	void swap(int& a,int& b){
		int c = a;
		a = b;
		b = c;
	}
	
	void reverse(vector<int> &p,int a,int b){
		int mid = (a+b)/2;
		for(int i=a;i<=mid;i++){
			swap(p[i],p[b-(i-a)]);
		}
	}

    void recoverRotatedSortedArray(vector<int> &nums) {
        int len = nums.size();
		if(len<2)
			return;
		int i=1;
		for(;i<len;i++)
			if(nums[i]<nums[i-1])
				break;
		if(i==len)
			return;
		reverse(nums,0,i-1);
		reverse(nums,i,len-1);
		reverse(nums,0,len-1);
    }
};