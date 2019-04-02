class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //用尽量小的饼干喂给胃口尽量小的孩子,贪心法
		//如果s[j]不能满足g[i],也不能满足g[i+k]
		//如果s[j]能满足g[i+k],一定也可以满足g[i]
		//排序然后从小到大做
		int glen = g.size();
		int slen = s.size();
		sort(g.begin(),g.end());
		sort(s.begin(),s.end());
		int i=0,j=0;
		int ans = 0;
		while(i<glen && j<slen){
			if(s[j]>=g[i]){
				ans++;
				i++;
			}
			j++;
		}
		return ans;
    }
};