class Solution {
public:
    string longestCommonPrefix(vector<string>& sv) {
		int vlen = sv.size();
		if(!vlen)
			return "";
		if(vlen==1)
			return sv[0];
		int minslen = sv[0].size();
		//计算最短字符串
		for(int i=1;i<vlen;i++) {
			int nowslen = sv[i].size();
			if(nowslen<minslen)
				minslen = nowslen;
		}
		//水平扫描
		int i = 0;
		for(;i<minslen;i++) {
			char c = sv[0][i];
			for(int j=1;j<vlen;j++) {
				if(sv[j][i]!=c)
					goto BYE;
			}
		}
		BYE:
		return sv[0].substr(0,i);
    }
};