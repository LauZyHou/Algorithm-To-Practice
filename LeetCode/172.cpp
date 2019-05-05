class Solution {
public:
    int trailingZeroes(int n) {
        long long time = 5;
		int ans = 0;
		while(n/time>0) {
			ans += n/time;
			time*=5;
		}
		return ans;
    }
};