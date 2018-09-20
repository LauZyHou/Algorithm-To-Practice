#include<bits/stdc++.h>
using namespace std;

void Permutation(char* pStr, char* pBegin);

//求字符串的排列,将其输出 
void Permutation(char* pStr) {
	if(pStr == nullptr)//仅仅多了一个非空校验 
		return;
	Permutation(pStr, pStr);
}

//递归函数,给出大字符串,给出子串首部指针(指向大字符串上的当前字符) 
void Permutation(char* pStr, char* pBegin) {
	if(*pBegin == '\0') {//如果指向了'\0',说明这个字符串已经排列完成了一次 
		printf("%s\n", pStr);//这时整个字符串是一个新的排列,将其输出 
	} else {//否则(没走到结尾)
		//从当前位置向后的所有位置 
		for(char* pCh = pBegin; *pCh != '\0'; ++ pCh) {
			//在这每个位置上,与当前位置的字符做交换 
			char temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;
			//然后递归地调用本函数,从下一位置开始的子串继续做此操作
			//以获取前面部分不动,而后面子串动时候的全排列 
			Permutation(pStr, pBegin + 1);
			//在下次循环前将"当前位置字符"交换回到当前位置,还原现场 
			temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;
		}
	}
}

int main() {
	char str[]="abcd";
	Permutation(str);
	return 0;
}
