class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
		map<int,int> cm;//该数字出现次数
		map<int,int> mini;//该数字最小索引
		map<int,int> maxi;//该数字最大索引
		int maxc = 0;//当前最大出现次数
		map<int,int>::iterator it;
		int nlen = nums.size();
		for(int i=0;i<nlen;i++){
			cm[nums[i]]++;
			if(cm[nums[i]]>maxc)
				maxc = cm[nums[i]];
			if(mini.find(nums[i])==mini.end() || mini[nums[i]]>i)
				mini[nums[i]] = i;
			if(maxi.find(nums[i])==maxi.end() || maxi[nums[i]]<i)
				maxi[nums[i]] = i;
		}
		int ans = INT_MAX;
		for(it=cm.begin();it!=cm.end();it++){
			if(it->second==maxc){
				int len = maxi[it->first]-mini[it->first]+1;
				if(len<ans)
					ans = len;
			}
		}
		return ans;
    }
};