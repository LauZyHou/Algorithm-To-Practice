#include<bits/stdc++.h>
using namespace std;

//输入数组的string常引用,输出满足条件的最大的f(i)的值 
int longestSubstringWithoutDuplication(const string& str) {
	int curLength = 0;//当前找到的长度,即当前的f(i) 
	int maxLength = 0;//到当前为止,最大的f(i) 

	int* position = new int[26];//存26个字母"上一次出现的位置下标"
	for(int i = 0; i < 26; ++i) 
		position[i] = -1;//初始化为-1,表示"之前没出现过" 

	for(int i = 0; i < str.length(); ++i) {//遍历字符串 
		int prevIndex = position[str[i] - 'a'];//该位置字符上一次出现的位置下标 
		if(prevIndex < 0 || i - prevIndex > curLength)//情况①或② 
			++curLength;//f(i)=f(i-1)+1
			//反复出现这种情况时,curLength是单调增加的
			//所以不需要担心漏记录了中间出现的某些比两边大的长度
			//不可能出现,因为是单调增加的(单调减少就不行)
			//这时不对maxLength做无用的更新,因为更新了也会被后面的更新覆盖掉 
		else {//情况③ 
			if(curLength > maxLength)//更新最大f(i) 
				maxLength = curLength;
			curLength = i - prevIndex;//f(i)=d
		}
		position[str[i] - 'a'] = i;
	}
	//最终更新一次最大f(i),因为可能以情况①或者②结束 
	if(curLength > maxLength)
		maxLength = curLength;

	delete[] position;
	return maxLength;
}

int main() {
	string ok="abcacfrar";
	printf("%d\n",longestSubstringWithoutDuplication(ok));//4
	return 0;
}
