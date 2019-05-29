class Solution {
public:
	char s[300];
	char r[300];
    string convertToTitle(int n) {
		int len = 0;
		while(n) {
			int a = n%26;
			//特殊处理26的倍数,如52是'AZ'
			if(a==0) {
				s[len++] = 'Z';
				n/=26;
				n--;
			}
			else {
				s[len++] = a+'A'-1;
				n/=26;
			}
		}
		for(int i=0;i<len;i++) {
			r[i] = s[len-i-1];
		}
		r[len] = '\0';
		return string(r);      
    }
};