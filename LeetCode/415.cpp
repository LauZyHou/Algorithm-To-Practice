class Solution {
public:
    string addStrings(string n1, string n2) {
        int len1 = n1.size();
		int len2 = n2.size();
		int i = 0;//bais
		char c[5110];
		int mx = max(len1,len2);
		c[mx+1] = '\0';
		int jw = 0;
		while(i<=mx-1){
			int s1 = len1-1-i>=0 ? n1[len1-1-i]-'0' : 0;
			int s2 = len2-1-i>=0 ? n2[len2-1-i]-'0' : 0;
			c[mx-i] = (s1 + s2 + jw)%10 + '0';
			jw = (s1 + s2 + jw)/10;
			i++;
		}
		//判断进位,有进位写进c[0]
		if(jw>0){
			c[0] = jw + '0';
			return string(c);
		}
		return string(c+1);
    }
};