class Solution {
public:
    int maxArea(vector<int>& h) {
        int len = h.size();
		if(len<2)
			return 0;
		int l = 0;
		int r = len-1;
		int ans = 0;
		while(l<r) {
			ans = max(ans,(r-l)*min(h[r],h[l]));
			if(h[l]<h[r])
				l++;
			else
				r--;
		}
		return ans;
    }
};