static char a[3][10] = {
			{'q','w','e','r','t','y','u','i','o','p'},
			{'a','s','d','f','g','h','j','k','l',' '},
			{'z','x','c','v','b','n','m',' ',' ',' '}};

set<char> s[3];

class Solution {
public:
	int findInSet(char c){
		for(int i=0;i<3;i++)
			if(s[i].count(c))
				return i;
		return -1;
	}

    vector<string> findWords(vector<string>& words) {
		
		vector<string> ans;

		for(int j=0;j<3;j++)
			for(int i=0;i<10;i++){
				if(a[j][i]==' ')
					break;
				s[j].insert(a[j][i]);
				s[j].insert(a[j][i]-'a'+'A');
			}
		for(int i=0;i<words.size();i++){
			int same = findInSet(words[i][0]);
			int k=0;
			for(;k<words[i].size();k++){
				if(findInSet(words[i][k])!=same)
					break;
			}
			if(k<words[i].size())//not same
				continue;
			//same,append it
			ans.push_back(words[i]);
		}
		return ans;
    }
};