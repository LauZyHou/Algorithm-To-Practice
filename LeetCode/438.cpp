class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
		vector<int> ans;
		int slen = s.size();
		if(!slen)
			return ans;
		int plen = p.size();
		if(!plen || plen>slen)
			return ans;
		//记录每个字母出现多少次
		int a[26]={0};
		//计算有多少种字母为0(没有),这个用于判定匹配
		int nz = 26;
		for(int i=0;i<plen;i++){
			if(a[p[i]-'a']==0)
				nz--;
			a[p[i]-'a']++;	
		}
		for(int i=0;i<slen;i++){
			//如果超过plen个字母,每次要把最前面一个字母去掉(也就是在表中加回来)
			if(i>=plen){
				//去掉最前面的字母
				//判定一下当前次数,如果已经是0那要记得总为0数-1
				if(a[s[i-plen]-'a']==0)
					nz--;
				a[s[i-plen]-'a']++;
				//如果加回来之后是0,那么总为0数要+1
				if(a[s[i-plen]-'a']==0)
					nz++;
			}
			//把当前字母记录进来(即从表项中删去一个)
			//如果记录之前是0,那么记录后总为0数要-1
			if(a[s[i]-'a']==0)
				nz--;
			a[s[i]-'a']--;
			//如果记录之后是0.那么总为0数要+1
			if(a[s[i]-'a']==0)
				nz++;
			//如果26个字母都是0了,那么匹配成功
			if(i>=plen-1 && nz==26)
				ans.push_back(i-(plen-1));//记录的是起始位置索引
		}
		return ans;
	}
};