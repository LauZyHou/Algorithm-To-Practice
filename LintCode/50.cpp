class Solution {
public:
    /*
     * @param nums: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        //用两个数组分别保存前面所有项之积和后面所有项之积然后再用两个数组的每个位置对于相乘即可
		int len = nums.size();
		long long f[len];//前i项之乘积
		long long e[len];//后i项之乘积
		f[0] = e[0] = 1;
		for(int i=1;i<len;i++) {
			f[i] = f[i-1]*nums[i-1];
			e[i] = e[i-1]*nums[len-1-(i-1)];
		}
		vector<long long> ans;
		for(int i=0;i<len;i++){
			ans.push_back(f[i]*e[len-(i+1)]);
		}
		return ans;
    }
};