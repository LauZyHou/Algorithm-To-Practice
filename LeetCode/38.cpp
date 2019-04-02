class Solution {
public:
    string countAndSay(int n) {
        int cnt = 1;
		string s = "1";
		if(n==1)
			return s;
		int slen = 1;//s.size()
		while(cnt!=n){
			//用于生成下一个字符串,其长度不会超过上一个的两倍
			char* r = new char[2*slen+1];
			int i,j=0;
			char nc = s[0];
			int ncnum = 1;
			for(i=1;i<slen;i++){
				//相同往下计算
				if(s[i]==nc)
					ncnum++;
				//不同写进r里
				else{
					//先得到这个数字有多少个,写进去
					string t = to_string(ncnum);
					int tlen = t.size();
					for(int k=0;k<tlen;k++)
						r[j++] = t[k];
					//吧这个数字也写进去
					r[j++] = nc;
					//记录下一个数字了
					nc = s[i];
					ncnum = 1;
				}
			}
			//结束写进r里
			//先得到这个数字有多少个,写进去
			string t = to_string(ncnum);
			int tlen = t.size();
			for(int k=0;k<tlen;k++)
				r[j++] = t[k];
			//吧这个数字也写进去
			r[j++] = nc;

			//至此,在r中已经生成了"下一个字符串"
			r[j] = '\0';
			s = r;
			slen = j;
			cnt++;
			j = 0;
			delete[] r;
		}
		return s;
    }
};