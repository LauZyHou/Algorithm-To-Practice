class Solution {
public:
	void reverse(vector<int>& v, int a, int b) {
		if(b==a)
			return ;
		int mid = (b-a)/2;
		for(int i=0;i<=mid;i++)
			swap(v[a+i],v[b-i]);
	}

    void rotate(vector<int>& nums, int k) {
        if(!k)
			return ;
		int len = nums.size();
		if(!(k%len))
			return ;
		k = k%len;
		reverse(nums, 0, len-1);
		reverse(nums, 0, k-1);
		reverse(nums, k, len-1);
    }
};