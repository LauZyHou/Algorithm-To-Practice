class Solution {
public:
	
	int f(string& s) {
		int a[26] = {0};
		for(char c:s) {
			a[c-'a']++;
		}
		for(int i=0;i<26;i++) {
			if(a[i])
				return a[i];
		}
		return 0;
	}

    vector<int> numSmallerByFrequency(vector<string>& q, vector<string>& w) {
		int qlen = q.size();
		int wlen = w.size();
        vector<int> qn(qlen);
		vector<int> wn(wlen);
		for(int i=0;i<qlen;i++) {
			qn[i] = f(q[i]);
		}
		for(int i=0;i<wlen;i++) {
			wn[i] = f(w[i]);
		}
		sort(wn.begin(),wn.end(),greater<int>());
		vector<int> ans;
		for(int i=0;i<qlen;i++) {
			int j=0;
			while(j<wlen && qn[i]<wn[j])
				j++;
			ans.push_back(j);
		}
		return ans;
    }
};