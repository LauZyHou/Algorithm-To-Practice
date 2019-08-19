class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;//first放数值,second是数目
		for(int n:nums) {
			if(mp.find(n)==mp.end())
				mp[n] = 1;
			else
				mp[n]++;
		}
		using PP = pair<int,int>;//first是数目,second放数值
		priority_queue<PP,vector<PP>,greater<PP>> pq;//最小堆
		for(auto& m:mp) {//对每个出现的元素
			pair<int,int> p = make_pair(m.second,m.first);//在这里反过来
			if(pq.size()==k) {//再放就K+1了
				if(p<pq.top())//pair比较先比较first,这里即这个元素出现次数不如堆里最小的
					continue;//下一个
				else//否则
					pq.pop();//最小的弹出来
			}
			pq.push(p);
		}
		//至此,最小堆里的至多k个元素就是所求
		vector<int> ans(pq.size());//也可能不足k个,所以这里用PP.size()
		while(k--) {
			ans[k] = pq.top().second;
			pq.pop();
		}
		return ans;
    }
};