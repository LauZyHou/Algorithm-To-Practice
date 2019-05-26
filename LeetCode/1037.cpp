class Solution {
public:
    bool isBoomerang(vector<vector<int>>& vv) {
		//直接判断向量是否共线即可
		//AB = (x1, y1), BC = (x2, y2)
		int x1 = vv[1][0] - vv[0][0];
		int y1 = vv[1][1] - vv[0][1];
		int x2 = vv[2][0] - vv[1][0];
		int y2 = vv[2][1] - vv[1][1];
		return x1*y2 != x2*y1;
    }
};