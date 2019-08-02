class Solution {
public:
	vector<int> productExceptSelf(vector<int>& v) {
		int len = v.size();
		int* a = new int[len];
		int* b = new int[len];
		a[0] = 1;
		b[len-1] = 1;
		for(int i=1;i<len;i++) {
			a[i] = a[i-1] * v[i-1];
			b[len-1-i] = b[len-i] * v[len-i]; 
		}
		vector<int> ans(len);
		for(int i=0;i<len;i++) {
			ans[i] = a[i] * b[i];
		}
		delete[] a;
		delete[] b;
		return ans;
	}
};