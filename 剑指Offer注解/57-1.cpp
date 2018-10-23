#include<bits/stdc++.h>
using namespace std;

//在长为length的data数组里找和为sum的一对数字,存在*num1和*num2里,找到返回true 
bool FindNumbersWithSum(int data[], int length, int sum,
                        int* num1, int* num2) {
	bool found = false;//指示是否找到 
	if(length < 1 || num1 == nullptr || num2 == nullptr)//输入合法性检查 
		return found;

	int ahead = length - 1;//右边的游标 
	int behind = 0;//左边的游标 

	while(ahead > behind) {//游标还未相遇,可以继续找 
		long long curSum = data[ahead] + data[behind];//加和,int+int可能溢出所以用long long 

		if(curSum == sum) {//加起来正好相等即找到了 
			//将两数写进去 
			*num1 = data[behind];
			*num2 = data[ahead];
			found = true;//指示找到了 
			break;//结束循环 
		} else if(curSum > sum)//太大了 
			ahead --;//右边游标左移 
		else//太小了 
			behind ++;//左边游标右移 
	}
	return found;//指示找没找到 
}


int main() {
	int data[] = {1, 2, 4, 7, 11, 15};
	int n1,n2;
	if(FindNumbersWithSum(data,sizeof(data)/sizeof(int),15,&n1,&n2))
		cout<<n1<<","<<n2<<endl;//4,11
	return 0;
}
