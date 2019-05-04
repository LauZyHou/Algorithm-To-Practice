class Solution {
public:
	vector<string> split(string s,char p){
		int len = s.size();
		vector<string> ret;
		if(!len)
			return ret;
		char* a = new char[len+1];
		int j=0,i=0;
		for(i=0;i<len;i++){
			if(s[i]==p && j>0){
				a[j]='\0';
				ret.push_back(string(a));
				j=0;
			}
			else{
				a[j++] = s[i];
			}
		}
		//the end one
		if(j>0){
			a[j]='\0';
			ret.push_back(string(a));
		}
		delete[] a;
		return ret;
	}

    bool wordPattern(string pattern, string str) {
		vector<string> sv = split(str,' ');
		//for(auto st:sv)
		//	cout<<st<<endl;
		int len = pattern.size();
		if(len!=sv.size())
			return false;
		unordered_map<char,string> p2s;
		unordered_map<string,char> s2p;
		for(int i=0;i<len;i++){
			p2s[pattern[i]] = sv[i];
			s2p[sv[i]] = pattern[i];
		}
		//check them
		for(int i=0;i<len;i++)
			if(pattern[i]!=s2p[sv[i]] || sv[i]!=p2s[pattern[i]])
				return false;
		return true;
	}
};