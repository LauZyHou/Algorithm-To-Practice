#include<bits/stdc++.h>
using namespace std;

//翻转从pBegin到pEnd的字符串
void Reverse(char *pBegin, char *pEnd) {
	if(pBegin == nullptr || pEnd == nullptr)//输入合法性检查
		return;

	while(pBegin < pEnd) {
		//交换对称位置的字符
		char temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;
		//对称地向中间移动
		pBegin ++, pEnd --;
	}
}

//左旋字符串,左旋位置是n 
char* LeftRotateString(char* pStr, int n) {
	if(pStr != nullptr) {//字符串不能传空指针 
		int nLength = static_cast<int>(strlen(pStr));//长度 
		if(nLength > 0 && n > 0 && n < nLength) {//n和nLength的合法性 
			//左边的子串 
			char* pFirstStart = pStr;
			char* pFirstEnd = pStr + n - 1;
			//右边的子串 
			char* pSecondStart = pStr + n;
			char* pSecondEnd = pStr + nLength - 1;

			//翻转字符串的前面n个字符
			Reverse(pFirstStart, pFirstEnd);
			//翻转字符串的后面部分
			Reverse(pSecondStart, pSecondEnd);
			//翻转整个字符串
			Reverse(pFirstStart, pSecondEnd);
		}
	}
	return pStr;
}

int main() {
	char input[] = "abcdefg";
	printf("%s\n",LeftRotateString(input,2));//cdefgab
	return 0;
}
