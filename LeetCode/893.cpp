class Solution {
public:
	string myjoin(int* p) {
		string s = "";
		for(int i=0;i<52;i++) {
			if(p[i]) {
				s += "-";
				s += to_string(p[i]);
			} else {
				s += "-0";
			}
		}
		return s;
	}

    int numSpecialEquivGroups(vector<string>& v) {
        unordered_set<string> st;
		for(string s : v) {
			int ok[52] = {0};
			int slen = s.size();
			for(int i=0;i<slen;i++) {
				ok[s[i]-'a'+(i&1)*26]++;
			}
			st.insert(myjoin(ok));//只是为了能唯一表示这52个数
		}
		return st.size();
    }
};