class Solution {
public:
	int string2int(string s) {
		int len = s.size();
		if(!len)
			return 0;
		int ret = 0;
		int begin = 0;
		int c = 1;
		if(s[0]=='-') {
			begin = 1;
			c = -1;
		}
		for(;begin<len;begin++) {
			ret = ret*10 + s[begin]-'0';
		}
		return c*ret;
	}

    string complexNumberMultiply(string a, string b) {
        int alen = a.size();
		int blen = b.size();
		int cut = 0;
		int as,ax,bs,bx;
		stringstream ss;

		/*a的*/
		for(cut=0;cut<alen;cut++)
			if(a[cut]=='+')
				break;
		as = string2int(a.substr(0,cut));
		ax = string2int(a.substr(cut+1,alen-cut-2));

		/*b的*/
		for(cut=0;cut<blen;cut++)
			if(b[cut]=='+')
				break;
		bs = string2int(b.substr(0,cut));
		bx = string2int(b.substr(cut+1,blen-cut-2));

		//cout<<as<<","<<ax<<","<<bs<<","<<bx<<endl;

		int cs = as*bs - ax*bx;
		int cx = as*bx + ax*bs;
		return to_string(cs) + "+" + to_string(cx) + "i";
    }
};