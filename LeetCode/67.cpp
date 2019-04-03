class Solution {
public:
    string addBinary(string a, string b) {
        int alen = a.size();
		int blen = b.size();
		int aslen = max(alen,blen);
		string ans(aslen,'0');
		//对其
		if(alen>blen){
			string tmp(alen-blen,'0');
			b = tmp + b;
		}else{
			string tmp(blen-alen,'0');
			a = tmp + a;
		}
		//诸位计算,最高位特殊处理
		for(int i=aslen-1;i>0;i--){
			ans[i] += a[i]-'0'+b[i]-'0';
			if(ans[i]>='2'){
				ans[i-1] = '1';
				ans[i] -= 2;
			}
		}
		ans[0] += a[0]-'0'+b[0]-'0';
		if(ans[0]>='2'){
			ans[0] -= 2;
			string tmp = "1";
			ans = tmp + ans;
		}
		return ans;
    }
};