class Solution {
public:
	bool yuan(char c){
		return c=='a' || c=='e' || c=='i' || c=='o' || c=='u'
			|| c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
	}

    string reverseVowels(string s) {
		int len = s.size();
		int i = 0;
		int j = len-1;
		while(i<j){
			if(!yuan(s[i]))
				i++;
			else if(!yuan(s[j]))
				j--;
			else
				swap(s[i++],s[j--]);
		}
		return s;
    }
};