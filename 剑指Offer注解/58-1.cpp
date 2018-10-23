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

//旋转字符串,返回首地址(其实首地址没变,一直在操作指针指向的内容) 
char* ReverseSentence(char *pData) {
	if(pData == nullptr) 
		return nullptr;

	char *pBegin = pData;//开始之处 

	char *pEnd = pData;//寻找最后一个字符(结束符前一个字符) 
	while(*pEnd != '\0')
		pEnd ++;
	pEnd--;

	//翻转整个句子
	Reverse(pBegin, pEnd);

	//翻转句子中的每个单词
	pBegin = pEnd = pData;//两个指针都从头开始 
	while(*pBegin != '\0') {//pBegin走到结尾就表示所有单词都翻转完了 
		if(*pBegin == ' ') {//pBegin也走到了空格 
			//这时end肯定也在这个空格,一起向后走 
			pBegin ++;
			pEnd ++;
		} else if(*pEnd == ' ' || *pEnd == '\0') {//pBegin不在空格,但end在空格或者结束符 
			Reverse(pBegin, --pEnd);//翻转这个字符串 
			pBegin = ++pEnd;//pBegin和pEnd都踩在这个空格上 
		} else//pBegin不在空格上说明这是一个单词,pEnd不在空白上说明单词还没找完整 
			pEnd ++;//pEnd继续向后走,直到遇到空白(空格或结束符)
	}

	return pData;
}

int main() {
	char input[] = "I am a student.";
	printf("%s\n",ReverseSentence(input));//student. a am I
	return 0;
}
