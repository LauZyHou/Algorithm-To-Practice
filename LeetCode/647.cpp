class Solution {
public:
	int ans;
	int len;

	void check(string& s,int a,int b) {
		while(a>=0 && b<len) {
			if(s[a]!=s[b])
				return ;
			ans++;
			a--;
			b++;
		}
	}


    int countSubstrings(string s) {
		ans = 0;
        len = s.size();
		for(int i=0;i<len;i++) {
			//中心扩散
			check(s,i,i);//奇数的
			check(s,i,i+1);//偶数的
		}
		return ans;
    }
};