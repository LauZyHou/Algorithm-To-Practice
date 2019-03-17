class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
		int len = s.size();
		for(int i=0;i<len/2;i++){
			if(s[i]!=s[len-i-1])
				return false;
		}
		return true;
    }
};