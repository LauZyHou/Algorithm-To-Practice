class Solution {
public:
    bool isLongPressedName(string name, string typed) {
		int t=0,n=0;
		int now=-1;
		int nlen = name.size();
		int tlen = typed.size();
		while(n<nlen && t<tlen) {
			if(name[n]!=typed[t])
				return false;
			while(name[n]==typed[t] && n<nlen && t<tlen){
				n++;
				t++;
			}
			while(typed[t]==name[n-1] && t<tlen)
				t++;
		}
		if(n<nlen || t<tlen)
			return false;
		return true;
    }
};