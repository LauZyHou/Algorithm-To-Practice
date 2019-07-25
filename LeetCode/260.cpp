class Solution {
public:
    vector<int> singleNumber(vector<int>& v) {
        int len = v.size();
		int xorAll = 0;
		for(int i=0;i<len;i++)
			xorAll ^= v[i];
		//a & (-a) 可以获得a最低的非0位
		int lastNot0 = xorAll & (-xorAll);
		int ans1 = 0;
		int ans0 = 0;
		for(int i=0;i<len;i++) {
			if((v[i] & lastNot0)!=0)
				ans1 ^= v[i];
			else
				ans0 ^= v[i];
		}
		vector<int> ans(2);
		ans[0] = ans0;
		ans[1] = ans1;
		return ans;
    }
};