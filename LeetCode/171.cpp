class Solution {
public:
    int titleToNumber(string s) {
		if(s.length()<=0)
			return 0;
        long long cnt=0;
		for(int i=0;i<s.length();i++){
			cnt=cnt*26+s[i]-'A'+1;
		}
		return cnt;
	}
};