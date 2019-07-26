class Solution {
public:
    int minAddToMakeValid(string S) {
        int len = S.size();
		int leftAns = 0;//左侧添加左括号数量
		int stack = 0;//模拟栈,栈里放左括号,遇到右括号就出栈一个
		for(int i=0;i<len;i++) {
			if(S[i]=='(') {
				stack++;
			} else {
				if(stack==0)
					leftAns++;
				else
					stack--;
			}
		}
		stack = 0;//清空模拟栈,栈里放右括号,遇到左括号就出栈一个
		int rightAns = 0;//右侧添加右括号数量
		for(int i=len-1;i>=0;i--) {
			if(S[i]==')') {
				stack++;
			} else {
				if(stack==0)
					rightAns++;
				else
					stack--;
			}
		}
		return leftAns + rightAns;
    }
};