class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.size();
		if(len<2)
			return false;
		set<int> st;
		st.insert(1);
		int n = len/2;
		for(int i=2;i<=n;i++)
			if(0==len%i)
				st.insert(i);
		for(int i:st){
			int j=i;
			for(j=i;i<len;j++)
				if(s[j]!=s[j%i])
					break;
			if(j==len)
				return true;
		}
		return false;
    }
};