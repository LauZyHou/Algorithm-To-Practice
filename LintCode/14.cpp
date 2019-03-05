class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target to find.
     * @return: The first position of target. Position starts from 0.
     */

	int bs(vector<int> &v,int a,int b,int t){
		if(a==b){
			return v[a]==t?a:-1;
		}
		int k = (a+b)/2;
		if(v[k]==t && (k==a || v[k-1]!=t))//最左一个
			return k;
		if(v[k]<t)
			return bs(v,k+1,b,t);
		else//>=都往左找,这样有相同的数字时候找到的是第一次出现的那个数字
			return bs(v,a,k-1,t);
	}

    int binarySearch(vector<int> &nums, int target) {
		return bs(nums,0,nums.size()-1,target);
    }
};