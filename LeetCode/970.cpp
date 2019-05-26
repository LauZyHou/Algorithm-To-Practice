class Solution {
public:
	int pow(int x,int k) {
		int ret = 1;
		for(int i=0;i<k;i++)
			ret = ret*x;
		return ret;
	}

    vector<int> powerfulIntegers(int x, int y, int bound) {
		//bound最大1000000
		//2的20次方大于这个数
		int xval, yval;
		set<int> st;
		for(int i=0;i<20 && (xval=pow(x,i))<bound;i++)
			for(int j=0;j<20 && (yval=pow(y,j))<bound;j++) {
				int val = xval + yval;
				if(val<=bound)
					st.insert(val);
			}
		set<int>::iterator it;
		vector<int> ans;
		for(it=st.begin();it!=st.end();it++) {
			ans.push_back(*it);
		}
		sort(ans.begin(),ans.end());
		return ans;
	}
};