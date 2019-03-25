//可以使用sum[i]存储nums到下标为i的(前i+1个)元素的和
//则可得到i~j子区间的和为sum[j]-sum[i-1] if i>0 else sum[j]

class NumArray {
private:
	int *s = nullptr;
public:
    NumArray(vector<int> nums) {
        int len = nums.size();
		s = new int[len];
		int sums = 0;
		for(int i=0;i<len;i++){
			sums += nums[i];
			s[i] = sums;
		}
    }

	~NumArray(){
		delete[] s;
	}
    
    int sumRange(int i, int j) {
		if(i>0)
			return s[j]-s[i-1];
		return s[j];
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */