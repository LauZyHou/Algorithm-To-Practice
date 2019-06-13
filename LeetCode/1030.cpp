class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
		//这题是语法题
		//假设摊平来存,每个位置存一个长度为3的vec,其中是i坐标,j坐标,街道距离
		//街道距离放在最后,方便删除
		vector<vector<int>> v(R*C,vector<int>(3));
		//构造它
		for(int i=0;i<R;i++) {
			for(int j=0;j<C;j++) {
				v[i*C+j][0] = i;
				v[i*C+j][1] = j;
				v[i*C+j][2] = abs(i-r0) + abs(j-c0);
			}
		}
		//排序
		sort(v.begin(),v.end(),upv2);
		//删除街道距离
		int len = R*C;
		for(int i=0;i<len;i++) {
			v[i].pop_back();
		}
		return v;
    }

	static bool upv2(vector<int>& a,vector<int>& b) {
		return a[2]<b[2];//按照vec中第3个元素升序排序,这里也就是按街道距离
	}
};