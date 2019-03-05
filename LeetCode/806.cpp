class Solution {
public:
    vector<int> numberOfLines(vector<int>& w, string s) {
		int slen = s.size();
		int cnt = 0;
		int lines = 0;
		for(int i=0;i<slen;i++){
			int now = w[s[i]-'a'];
			cnt += now;
			if(cnt>100){
				cnt=0;
				i--;
				lines++;
			}
		}
		vector<int> v;
		v.push_back(lines+1);
		v.push_back(cnt);
		return v;
    }
};