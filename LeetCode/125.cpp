class Solution {
public:
	bool dx(char c){
		return c<='Z' && c>='A';
	}

	bool xx_or_sz(char c){
		return c<='z' && c>='a' || c<='9' && c>='0';
	}

    bool isPalindrome(string s) {
        int len = s.size();
		int i = 0;
		int j = len-1;
		while(i<j){
			while(i<j && !dx(s[i]) && !xx_or_sz(s[i]))
				i++;
			while(i<j && !dx(s[j]) && !xx_or_sz(s[j]))
				j--;
			if(i>=j)
				break;
			char a = s[i];
			if(dx(a))
				a = a-'A'+'a';
			char b = s[j];
			if(dx(b))
				b = b-'A'+'a';
			if(a!=b)
				return false;
			i++,j--;
		}
		return true;
    }
};