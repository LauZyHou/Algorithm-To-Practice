class Solution {
public:
    string convertToBase7(int num) {
		char c[101];
		c[100] = '\0';
		int r = 99;
		bool fu = false;
		if(num<0){
			fu = true;
			num = -num;
		}
		for(int i=99;i>=0;i--){
			int t = num%7;
			c[r--] = t+'0';
			num/=7;
			if(!num)
				break;
		}
		if(fu)
			c[r--] = '-';
		string ans(c+r+1);
		return ans;
    }
};