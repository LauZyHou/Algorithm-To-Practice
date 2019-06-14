class Solution {
public:
    int scoreOfParentheses(string S) {
        // (()(()))
		// 121			+2
		//   1242		+4
		//      210
		//每次到闭合括号时在sum里加上计算出来的数
		//遇到左括号时,乘以2,即左移一位
		//遇到右括号时,除以2,即右移一位
		int len = S.size();
		int sum = 0;
		int n = 0;
		for(int i=0;i<len;i++) {
			char c = S[i];
			if(c=='(') {
				if(n==0)
					n=1;
				else
					n<<=1;
			}
			else if(c==')') {
				//闭合括号
				if(i>0 && S[i-1]=='(')
					sum += n;
				n>>=1;
			}
		}
		return sum;
	}
};