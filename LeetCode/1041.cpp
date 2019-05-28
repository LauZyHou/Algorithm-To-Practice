/*
初始朝向只要变了,那么四次一定能回来(四条方向向量组成正方形)
初始朝向没变的话,那么x坐标和y坐标都必须没有发生变化(也就是还是0)
*/
class Solution {
public:
	//上右下左走一步
	int to[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    bool isRobotBounded(string s) {
        int a=0,b=0;
		int dir = 0;
		for(auto c : s) {
			if(c=='G') {
				a += to[dir][0];
				b += to[dir][1];
			}
			else if(c=='L')
				dir = (dir+3)%4;
			else if(c=='R')
				dir = (dir+1)%4;
		}
		if(dir!=0)
			return true;
		return a==0 && b==0;
    }
};