class Solution {
public:
    int countPrimes(int n) {
		vector<bool> v(n,true);
		int ans = 0;
		int y = sqrt(n);
		for(int i=2;i<=y;i++) {
			if(v[i]==true) {
				int k = i;
				while(k*i<n) {
					v[k*i] = false;
					k++;
				}
			}
		}
		for(int i=2;i<n;i++) {
			if(v[i])
				ans++;
		}
		return ans;
	}
};