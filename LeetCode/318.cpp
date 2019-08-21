class Solution {
public:
    int maxProduct(vector<string>& words) {
		int wlen = words.size();
		int* p = new int[wlen];
        for(int i=0;i<wlen;i++) {
			p[i] = 0;
			int slen = words[i].size();
			for(int j=0;j<slen;j++) {
				p[i] |= (1<<(words[i][j]-'a'));
			}
		}
		int ans = 0;
		for(int i=0;i<wlen;i++) {
			for(int j=0;j<wlen;j++) {
				if((p[i]&p[j])==0) {
					int r = words[i].size() * words[j].size();
					if(r>ans)
						ans = r;
				}
			}
		}
		return ans;
    }
};