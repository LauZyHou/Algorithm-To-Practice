class Solution {
public:
	int gcd(int a,int b) {
		int t = a%b;
		if(t==0)
			return b;
		return gcd(b,t);
	}

	bool match(string a,string t) {
		int alen = a.size();
		int tlen = t.size();
		for(int i=0;i<alen;i++) {
			if(a[i]!=t[i%tlen])
				return false;
		}
		return true;
	}

    string gcdOfStrings(string str1, string str2) {
		int len1 = str1.size();
		int len2 = str2.size();
		int len = gcd(len1,len2);
		string ans = str1.substr(0,len);
		//这里,所求的字符串的长度一定是len,如果是len的因数,那len也一定可以
		if(match(str1,ans) && match(str2,ans))
			return ans;
		return "";
	}
};