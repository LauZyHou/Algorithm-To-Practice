class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int len = A.size();
		if(len<3) return 0;
		vector<int> cha(len-1);
		for(int i=0;i<len-1;i++)
			cha[i] = A[i+1] - A[i];
		vector<int> p;
		int cnt = 1;
		int val = cha[0];
		for(int i=1;i<len-1;i++) {
			if(cha[i]==val)
				cnt++;
			else {
				p.push_back(cnt);
				val = cha[i];
				cnt = 1;
			}
		}
		p.push_back(cnt);
		int ans = 0;
		for(auto a:p) {
			if(a<2) continue;
			ans += a*(a-1)/2;
		}
		return ans;
    }
};