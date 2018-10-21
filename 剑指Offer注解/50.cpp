#include<bits/stdc++.h>
using namespace std;

//输入字符数组地址,输出寻找到的第一个只出现一次的字符 
char FirstNotRepeatingChar(const char* pString) {
	if(pString == nullptr)//空串没有只出现一次的字符
		//实际上它也是个ASCII字符,但以其作为字符串结尾
		return '\0';//在这种情况下,也确实可以认定'\0'是第一次出现一次的 

	const int tableSize = 256;//字符表大小 
	unsigned int hashTable[tableSize];//创建字符表,字符出现次数不能为负 
	for(unsigned int i = 0; i < tableSize; ++i)//全部初始化为出现0次 
		hashTable[i] = 0;

	const char* pHashKey = pString;//指针从字符串首开始 
	while(*(pHashKey) != '\0')//第一次遍历整个字符串,出现次数记录到表中 
		hashTable[*(pHashKey++)] ++;//hashTable[*pHashKey]++,pHashKey++

	pHashKey = pString;//再次从头开始 
	while(*pHashKey != '\0') {//遍历整个字符串 
		if(hashTable[*pHashKey] == 1)//找到第一个出现一次的字符 
			return *pHashKey;//将其直接返回 
		//当前字符不止出现一次,继续找下一个 
		pHashKey++;
	}
	//没找到只出现一次的字符 
	return '\0';//也可以认为是串结束符一定只出现一次 
}

int main() {
	cout<<FirstNotRepeatingChar("google")<<endl;//l
	return 0;
}
