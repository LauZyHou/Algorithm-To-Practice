#include<bits/stdc++.h>
using namespace std;

bool matchCore(const char* str, const char* pattern);

// 参数:
//        str:       要匹配的字符串首地址 
//        pattern:   要匹配的模式串首地址 
// 返回值:
//        能否匹配成功 
bool match(const char* str, const char* pattern) {
	//非空校验 
	if(str == nullptr || pattern == nullptr)
		return false;
	//调用匹配的函数,递归地进行匹配 
	return matchCore(str, pattern);
}

// 参数:
//        str:       要匹配的字符(子)串首地址 
//        pattern:   要匹配的模式(子)串首地址 
// 返回值:
//        从此位置向后能否匹配成功 
bool matchCore(const char* str, const char* pattern) {
	if(*str == '\0' && *pattern == '\0')//如果两串都到达结尾 
		return true;//匹配成功 

	if(*str != '\0' && *pattern == '\0')//如果模式串先到达结尾 
		return false;//匹配一定失败
	
	//另:如果字符串先到达结尾,不一定匹配失败,因为可能模式串剩下'a*'或者'*'可以匹配空 

	//如果模式串下一字符是'*',那么会影响当前字符的匹配长度 
	if(*(pattern + 1) == '*') {
		//如果当前模式是和字符串匹配的,或者当前模式是'.'可匹配任一字符 
		if(*pattern == *str || (*pattern == '.' && *str != '\0'))//即如果当前是匹配的 
			//考虑三种匹配方式
			//跳过当前字符串上的'a',跳过模式串'a*',即'*'使'a'重复1次 
			return matchCore(str + 1, pattern + 2)
			       //跳过当前字符串上的'a',期望后面的'a'还能匹配'a*',即'*'使'a'重复>1次  
			       || matchCore(str + 1, pattern)
			       //跳过模式串'a*',即'*'使'a'重复0次
			       || matchCore(str, pattern + 2); 
		else//如果当前模式不能匹配字符串上的这个字符 
			//这时这个'*'号只能起到使前面的字符'a'重复0次的效果 
			return matchCore(str, pattern + 2);
	}

	//以下是后面没有跟'*'的情况 

	//如果当前模式匹配字符串该位置的字符('a'-'a'匹配或者'a'-'.'匹配) 
	if(*str == *pattern || (*pattern == '.' && *str != '\0'))
		return matchCore(str + 1, pattern + 1);//匹配,两个串都前进一步 
	
	//至此还没有返回,说明这个(子)匹配已经失败 
	return false;
}

int main(){
	cout<<boolalpha<<match("aaca","ab*a*c*a")<<endl;
	return 0;
}
