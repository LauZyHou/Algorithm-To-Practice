class Solution {
public:
	vector<vector<string>> ans;
	string s;
	int len;

	bool isHW(int a,int b) {
		for(int i=a;i<=(a+b)/2;i++) {
			if(s[i]!=s[b-i+a])
				return false;
		}
		return true;
	}

	void traceback(vector<string>& v,int n) {
		if(n==len) {
			ans.push_back(vector<string>(v));
			return ;
		}
		for(int i=n;i<len;i++) {
			if(isHW(n,i)) {
				v.push_back(s.substr(n,i-n+1));
				traceback(v,i+1);
				v.pop_back();
			}
		}
	}

	vector<vector<string>> partition(string s) {
		ans = vector<vector<string>>();
		this->s = s;
		len = s.size();
		vector<string> fg;//用于存递归中搞出来的分割
		traceback(fg,0);
		return ans;
	}
};