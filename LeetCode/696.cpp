class Solution {
public:
    int countBinarySubstrings(string s) {
		int last = 0;
		int now = 1;
		int ans = 0;
		int len = s.size();
		if(!len)
			return 0;
		for(int i=1;i<len;i++){
			if(s[i]==s[i-1])
				now++;
			else{
				last = now;
				now = 1;
			}
			//check
			if(last>=now)
				ans++;
		}
		return ans;
    }
};