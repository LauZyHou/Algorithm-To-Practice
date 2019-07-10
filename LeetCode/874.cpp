struct PIIHashHasher
{
	size_t operator()(const pair<int,int> &k) const noexcept
	{
		return std::hash<string>{}(to_string(k.first)+","+to_string(k.second));
	}
};

struct PIIHashComparator
{
	bool operator()(const pair<int,int> &k1, const pair<int,int> &k2) const noexcept
	{
		return k1.first == k2.first && k1.second == k2.second;
	}
};

class Solution {
public:
	int fac[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

    int robotSim(vector<int>& cv, vector<vector<int>>& ovv) {
		int di = 0;//now direction
		int x = 0;
		int y = 0;

		//把障碍物存到集合里,方便查找 #技巧
		unordered_set<pair<int,int>,PIIHashHasher,PIIHashComparator> us;
		for(vector<int> ov:ovv)
			us.insert(make_pair(ov[0],ov[1]));

		//注意是求最大距离,而不是全走完的那个位置的距离 #易错点
		int ans = 0;

		//模拟指令
		for(int c:cv) {
			if(c==-2)//左转
				di = (di-1+4)%4;
			else if(c==-1)//右转
				di = (di+1)%4;
			else {//直走 #难点
				//模拟一步一步走
				for(int i=0;i<c;i++) {
					x += fac[di][0];
					y += fac[di][1];
					//看看这样走是不是撞上障碍物,如果撞到了就回退这步
					if(us.find(make_pair(x,y))!=us.end()) {
						//cout<<"撞了"<<endl;
						x -= fac[di][0];
						y -= fac[di][1];
						//当下这个位置往这个方向后续都不用再走了
						break;
					}
				}
				ans = max(ans,x*x+y*y);
			}
		}

		return ans;
    }
};