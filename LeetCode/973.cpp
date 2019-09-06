//尝试重载pair或者vector都没用,自己写个struct

struct point
{
	int x;
	int y;
	bool operator < (const point& p) const {
		return x*x+y*y < p.x*p.x+p.y*p.y;
	}

	bool operator > (const point& p) const {
		return x*x+y*y > p.x*p.x+p.y*p.y;
	}
};

class Solution {
public:

    vector<vector<int> > kClosest(vector<vector<int>>& vv, int K) {
        int len = vv.size();
		if(len<=K)
			return vv;
		priority_queue<point, vector<point>, less<point> > pq;
		for(int i=0;i<len;i++) {
			point p;
			p.x = vv[i][0];
			p.y = vv[i][1];
			if(pq.size()<K)
				pq.push(p);
			else if(pq.top()>p) {
				pq.pop();
				pq.push(p);
			}
		}

		int i = 0;
		int pqLen = pq.size();
		vector<vector<int> > ans(pqLen);
		while(i<pqLen) {
			vector<int> v(2);
			v[0] = pq.top().x;
			v[1] = pq.top().y;
			ans[i++] = v;
			pq.pop();
		}
		return ans;
    }
};