#define reg register

class Solution {
public:
    bool checkRecord(string s) {
        char now;
		int a=0;
		int l=0;
		int len = s.size();
		if(!len)
			return true;
		now = s[0];
		if(s[0]=='A')
			a++;
		for(int i=1;i<len;i++){
			if(s[i]=='A'){
				a++;
				if(a>1)
					return false;
			}else if(i>1 && s[i]=='L' && s[i-1]=='L' && s[i-2]=='L'){
				return false;
			}
		}
		return true;
    }
};