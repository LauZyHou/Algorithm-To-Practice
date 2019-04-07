class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int a[200],b[200];
		int slen = S.size();
		int tlen = T.size();
		int k=0,r=0;
		for(int i=0;i<slen;i++){
			if(S[i]!='#')
				a[k++] = S[i];
			else if(k>0)
				k--;
		}
		for(int i=0;i<tlen;i++){
			if(T[i]!='#')
				b[r++] = T[i];
			else if(r>0)
				r--;
		}
		if(r!=k)
			return false;
		for(int i=0;i<r;i++){
			if(a[i]!=b[i])
				return false;
		}
		return true;
    }
};