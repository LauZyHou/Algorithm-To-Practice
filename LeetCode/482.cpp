class Solution {
public:
    string licenseKeyFormatting(string s, int K) {
		int len = s.size();
		int alen = len*2;//当K取1时若s中没有'-'取到最大长度2*len-1,另需一位'\0'
		//记录字母
		char* a = new char[alen+1];//为了方便,浪费一位
		a[alen] = '\0';
		//alen-j-cnt为数组a的当前索引,这里用从1开始增加方便计数取模
		int j = 1;//字母的计数
		int cnt = 0;//'-'号的计数
		//从后往前扫描
		for(int i=len-1;i>=0;i--){
			if(s[i]=='-')
				continue;
			if(s[i]<='z' && s[i]>='a')
				s[i] = s[i]-'a'+'A';
			a[alen-j-cnt] = s[i];
			//如K=3,j从1,2,3是一组,接下来就是新的一组了
			if(j%K==0){
				cnt++;
				a[alen-j-cnt] = '-';
			}
			j++;
		}
		//去除最前面的'-'号(至多有1个)
		return a[alen-j-cnt+1]!='-' ? string(a+alen-j-cnt+1) : string(a+alen-j-cnt+2);
    }
};