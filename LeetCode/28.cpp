class Solution {
public:
	int* next = nullptr;
	
	void findnext(string p) {
		int len = p.size();
		next = new int[len];
		next[0] = -1;
		int k = -1;
		for(int j=0;j<len-1;j++) {
			while(k!=-1 && p[j]!=p[k]) {
				k = next[k];
			}
			//k终于为-1了,或者是找到了一个能和p[j]匹配的p[k]
			k++;
			next[j+1] = k;
		}
	}

    int strStr(string s, string p) {
        int slen = s.size();
		int plen = p.size();
		if(0==plen)
			return 0;
		if(plen>slen)
			return -1;
		this->findnext(p);
		int i = 0;
		int j = 0;
		while(i<slen && j<plen) {
			if(j==-1 || s[i]==p[j]) {
				i++;
				j++;
			}else {
				//匹配失败时模式串回退
				j = next[j];
			}
		}
		delete[] this->next;
		return j==plen ? i-plen : -1; 
    }
};