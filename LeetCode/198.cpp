class Solution {
public:
    int rob(vector<int>& v) {
        int ans = 0;
		int n = v.size();
		int* a = new int[n];
		for(int i=0;i<n;i++){
			if(i<2)
				a[i] = v[i];
			else if(i==2)
				a[i] = v[i]+a[i-2];
			else
				a[i] = max(a[i-2],a[i-3]) + v[i];
			if(a[i]>ans)
				ans = a[i];
		}
		return ans;
    }
};