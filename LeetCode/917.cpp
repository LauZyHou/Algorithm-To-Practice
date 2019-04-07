class Solution {
public:
	bool iszm(char c){
		return c<='z' && c>='a' || c<='Z' && c>='A';
	}

    string reverseOnlyLetters(string S) {
        int len = S.size();
		if(!len)
			return S;
		int i = 0,j = len-1;
		while(i<j){
			if(!iszm(S[i]))
				i++;
			else if(!iszm(S[j]))
				j--;
			else
				swap(S[i++],S[j--]);
		}
		return S;
    }
};