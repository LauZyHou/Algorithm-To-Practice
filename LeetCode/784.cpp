class Solution {
private:
	int t;
	vector<string> ans;
public:
	void backtrack(string s,int i){
		if(i==t)
			ans.push_back(s);
		else{
			if(s[i]<='z' && s[i]>='a'){
				backtrack(s,i+1);
				s[i] = s[i]-'a'+'A';
				backtrack(s,i+1);
			}else if(s[i]<='Z' && s[i]>='A'){
				backtrack(s,i+1);
				s[i] = s[i]-'A'+'a';
				backtrack(s,i+1);
			}else
				backtrack(s,i+1);
		}
	}

    vector<string> letterCasePermutation(string S) {
		t = S.size();
		backtrack(S,0);
		return ans;
    }
};