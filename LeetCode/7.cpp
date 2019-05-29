class Solution {
public:
    int reverse(int x) {
		if(0<=x && x<=9)
			return x;
		
        string s = to_string(x);
		int len = s.size();
		//判定最前面的负号
		int j = 0;
		if(s[0]=='-')
			j++;
		//找到后面有多少连续0
		int i = len-1;
		for(;i>=0;i--) {
			if(s[i]!='0')
				break;
		}
		//反向循环计算一下翻转后的数值
		long long ans = 0;
		for(int r = i;r>=j;r--) {
			ans = ans*10 + s[r]-'0';
		}
		if(ans>INT_MAX || ans<INT_MIN)
			return 0;
		return j>0 ? -ans : ans;
    }
};