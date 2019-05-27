class Solution {
public:
	//上右下左走一步
	int to[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
	//用于方位的转向
	int pos[4][2] = {{1,1},{}};
    bool isRobotBounded(string s) {
        int a=0,b=0;
		int dir = 0;
		int m=0,n=0;
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
		for(int i=0;i<4;i++) {
			n += b;
			m += a;
			if(!n && !m)
				return true;
		}
		/*
		n += b;
		m += a;
		if(!m && !n)
			return true;
		m += b;
		n -= a;
		if(!m && !n)
			return true;
		n -= b;
		m += a;
		if(!m && !n)
			return true;
		m -= b;
		n += a;
		if(!m && !n)
			return true;
		*/
		return false;
    }
};