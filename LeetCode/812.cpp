//https://wenda.so.com/q/1461992684722271

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& pnts) {
        int ans = 0;//平行四边形面积
		int len = pnts.size();
		if(len<3)
			return ans;
		for(int i=0;i<len-2;i++)
			for(int j=i+1;j<len-1;j++)
				for(int k=j+1;k<len;k++){
					int m = pnts[i][0]-pnts[j][0];
					int n = pnts[i][1]-pnts[j][1];
					int p = pnts[k][0]-pnts[j][0];
					int q = pnts[k][1]-pnts[j][1];
					ans = max(ans,abs(m*q-n*p));
				}
		return ans*1.0/2;
    }
};