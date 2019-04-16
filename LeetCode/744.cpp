class Solution {
public:
    char nextGreatestLetter(vector<char>& lt, char t) {
        int len = lt.size();
		int idx = -1;
		int nowmin = 26;
		for(int i=0;i<len;i++){
			if(lt[i]==t)
				continue;
			int sub = 26+lt[i]-'a'-t+'a';
			int x = sub%26;
			if(x<nowmin){
				nowmin = x;
				idx = i;
			}
		}
		return lt[idx];
    }
};