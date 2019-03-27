class Solution {	
public:
	void reverse(string& ok){
		int len = ok.size();
		int mid = len/2;
		for(int i=0;i<=mid;i++){
			char c = ok[i];
			ok[i] = ok[len-1-i];
			ok[len-1-i] = c;
		}
	}

    /*
     * @param s: A string
     * @return: A string
     */
    string reverseWords(string &s) {
		vector<string> ans;
		int len = s.size();
		if(!len)
			return "";
		int idx = -1;
		for(int i=0;i<len;i++){
			if(s[i]==' '){
				if(i>0 && s[i-1]!=' ' && idx>=0){
					string ok = s.substr(idx,i-idx);
					//reverse(ok);
					ans.push_back(ok);
					idx = -1;
				}
			}
			else if(idx < 0){
				idx = i;
			}
		}
		//特判
		if(s[len-1]!=' ' && idx>=0){
			string ok = s.substr(idx,len-1-idx+1);
			//reverse(ok);
			ans.push_back(ok);
		}
		//生成字符串
		string ret = "";
		int anslen = ans.size();
		for(int i=anslen-1;i>0;i--)
			ret += ans[i]+" ";
		if(anslen)
			ret += ans[0];
		return ret;
    }
};