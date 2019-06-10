class Solution {
public:
    bool buddyStrings(string A, string B) {
		int alen = A.size();
		int blen = B.size();
		if(alen!=blen)
			return false;
		int index[] = {-1,-1};
		int cnt = 0;
		unordered_map<char,int> mp;
		for(int i=0;i<alen;i++) {
			if(A[i]!=B[i]) {
				if(cnt==2)
					return false;
				index[cnt++] = i;
			}
			mp[A[i]]++;
		}
		//判断cnt(不同字符的数量
		if(cnt==0) {
			//只要有超过两个一样的字符就行了
			unordered_map<char,int>::iterator it;
			for(it = mp.begin();it!=mp.end();it++) {
				if(it->second>=2)
					return true;
			}
			return false;
		}
		else if(cnt==2) {
			return A[index[0]]==B[index[1]] && A[index[1]]==B[index[0]];
		}
		//这里只可能是cnt=1
		return false;
    }
};