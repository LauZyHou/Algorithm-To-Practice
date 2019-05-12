class Solution {
public:
    int maxDistToClosest(vector<int>& v) {
		//如果坐在最左边或者最右边,有几个连续0距离就是几
		//如果坐在中间,也就是两边肯定有1,距离是要除以2的
		int i = 0;
		int j = v.size()-1;
		int ans = 0;
		int now = 0;
		while(v[i++]!=1)
			ans++;
		while(v[j--]!=1)
			now++;
		ans = max(ans, now);
		//处理在中间的情况,不妨从左往右扫描
		while(i<=j){
			now = 0;
			while(v[i++]!=1)//j那边有1挡着的,不用怕过界
				now++;
			ans = max(ans, (now+1)/2);//如果是奇数个,如5距离最大是3
		}
		return ans;
    }
};