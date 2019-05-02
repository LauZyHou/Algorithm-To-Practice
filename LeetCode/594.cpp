class Solution {
public:
    int findLHS(vector<int>& nums) {
		//注意:子序列不要求连续,子串要求连续
		//用哈希表统计一下
		unordered_map<int,int> ump;
		for(int n:nums)
			if(ump.find(n)==ump.end())
				ump.insert(make_pair(n,1));
			else
				ump[n]++;
		int ans = 0;
		for(auto item:ump){
			//这里不能只有一个元素
			//ans = max(ans,ump[item.first]);
			if(ump.find(item.first+1)!=ump.end())
				ans = max(ans,ump[item.first+1]+ump[item.first]);
			if(ump.find(item.first-1)!=ump.end())
				ans = max(ans,ump[item.first-1]+ump[item.first]);
		}
		return ans;
    }
};