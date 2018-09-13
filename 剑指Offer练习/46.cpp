#include<bits/stdc++.h>
using namespace std;

int GetTranslationCount(const string& number);

//输入数字,返回翻译方法的种数 
int GetTranslationCount(int number) {
	if(number < 0)//输入合法性检查 
		return 0;
	//to_string将int转成string类型 
	string numberInString = to_string(number);
	return GetTranslationCount(numberInString);
}

//输入string表示的数字,返回翻译方法的种数
//使用常引用因为内部不改变字符串,且能避免一次拷贝构造 
int GetTranslationCount(const string& number) {
	int length = number.length();//字符串的长度,即有多少个数字 
	int* counts = new int[length];//该数组用于记录f(i) 
	int count = 0;//初始化所求"不同翻译的数目"为0 
	
	//从后向前扫描整个字符串 
	for(int i = length - 1; i >= 0; --i) {
		count = 0;//每次都先将count清空,因为每次是"从当前位置出发"的不同翻译数 
		if(i < length - 1)//只要i不是n-1即不是最后一个
			//f(i)初始化为f(i+1),后面只要考虑拼接两位数的问题 
			count = counts[i + 1]; 
		else//如果是n-1,即是最后一个 
			count = 1;//仅有一个数,那只有一种"翻译"方式 
		
		//只要不是最后一个数,要考虑拼接两位数的问题 
		//实际上可以将上面的逻辑一下,这个if就可以并上去了 
		if(i < length - 1) {
			int digit1 = number[i] - '0';//i位置的数 
			int digit2 = number[i + 1] - '0';//i+1位置的数 
			int converted = digit1 * 10 + digit2;//拼接一起成两位数 
			//判断是否在正确的范围内
			if(converted >= 10 && converted <= 25) {//如果在正确范围内 
				if(i < length - 2) //这里只有当i后面至少还有两个数时 
					count += counts[i + 2];//才存在f(i+2)这一说 
				else//i后面如果只有一个数,即i==length-2 
					count += 1;//这时它和后面这一个数拼起来即新的1种翻译 
			}
		}
		//count就是这次计算的f(i),用这种方式可以避免不停做数组内寻址 
		counts[i] = count;
	}

	count = counts[0];//最终所求就是从下标为0的数开始到结尾 
	delete[] counts;//释放堆空间 
	return count;
}

int main(){
	cout<<GetTranslationCount(12258)<<endl;	
	return 0;
} 
