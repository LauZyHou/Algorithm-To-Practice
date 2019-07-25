class Solution {
public:
	//查找s中c最后一次出现的位置
	//实际实现是从最后往前查,这样能快一些
	int myfind(string s,char c,int idx) {
		int slen = s.size();
		for(int i=slen-1;i>=idx;i--)
			if(s[i]==c)
				return i;
		return -1;
	}

    vector<int> partitionLabels(string s) {
		vector<int> ans;
        //贪心法
		int len = s.size();
		int begin = 0;//每个子串的开始位置
		int cur = begin;//查找中的游标(从子串开始到子串最后)
		int maxend = -2;//每个子串的结束位置,-2表示还没经历搜索
		while(begin<=len-1 && cur<=len-1) {//结束位置最大不能超过s的最后一位
			if(maxend==-2 || cur<maxend) {
				//查找最后一次出现的位置
				int end = myfind(s,s[cur],cur);
				if(end>maxend)
					maxend = end;
				//游标向下走
				cur++;
			}else {//也即cur>=maxend,在本程序中即cur==maxend
				//此时cur游标已经移动到了maxend位置,该串已经形成
				ans.push_back(maxend-begin+1);
				//下次循环开始搜下一个串
				begin = maxend+1;
				cur = begin;
				maxend = -2;
			}
		}
		//结束后,最后很可能还有一个串没进,只是因为cur超出去了
		if(begin<=len-1) {
			ans.push_back(cur-begin);
		}
		return ans;
    }
};