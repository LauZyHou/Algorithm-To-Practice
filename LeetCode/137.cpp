class Solution {
public:
    int singleNumber(vector<int>& v) {
        int len = v.size();
		int a[32] = {0};
		for(auto n:v) {
			int k = n;
			for(int i=0;i<32;i++) {
				if(k&1)
					a[i]++;
				k >>= 1;
			}
		}
		int ans = 0;
		for(int i=31;i>=0;i--) {
			ans <<= 1;
			if(a[i]%3) {
				ans++;
			}
		}
		return ans;
    }
};