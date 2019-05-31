class Solution {
public:
    int thirdMax(vector<int>& v) {
        int len = v.size();
		int a = INT_MIN;
		int b = INT_MIN;
		int c = INT_MIN;
		unordered_map<int,int> mp;
		for(int i=0;i<len;i++) {
			mp[v[i]] = 1;
			if(v[i]>a) {//比最大还大,更新前三大
				c = b;
				b = a;
				a = v[i];
			}
			//这里v[i]<a用于跳过重复
			else if(v[i]<a && v[i]>b) {//在最大和第二大之间,替换第二大,并更新第三大
				c = b;
				b = v[i];
			}
			//这里也是跳过重复
			else if(v[i]<b && v[i]>c) {
				c = v[i];
			}
		}
		int cnt = 0;
		unordered_map<int,int>::iterator it;
		for(it=mp.begin();it!=mp.end();it++)
			cnt++;
		return cnt<3 ? a : c;
    }
};