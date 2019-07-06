class Solution {
public:
    vector<int> distributeCandies(int c, int np) {
		vector<int> ans(np);
		int ss = (1+np)*np/2;
		int j = 0;//底下铺的平,一次铺np*np
		while(c > ss+j*np*np) {
			c -= ss+j*np*np;
			j++;
		}
		for(int i=0;i<np;i++) {
			ans[i] = (i+1)*j + np*(j-1)*j/2;
		}
		for(int i=0;i<np;i++) {
			if(c > j*np+i+1) {
				c -= j*np+i+1;
				ans[i] += j*np+i+1;
			}
			else {
				ans[i] += c;
				break;
			}
		}
		return ans;
    }
};