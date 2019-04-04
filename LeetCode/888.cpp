class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        vector<int> ans;
		int alen = A.size();
		int blen = B.size();
		if(!alen || !blen)
			return ans;
		int as = 0;
		int bs = 0;
		for(auto a : A){
			as += a;
		}
		set<int> sb;
		for(auto b : B){
			bs += b;
			sb.insert(b);
		}
		int cha = bs-as;
		if((cha&1)==1)
			return ans;
		cha /= 2;
		for(auto a : A){
			if(sb.count(a+cha)){
				ans.push_back(a);
				ans.push_back(a+cha);
				return ans;
			}
		}
		return ans;
    }
};