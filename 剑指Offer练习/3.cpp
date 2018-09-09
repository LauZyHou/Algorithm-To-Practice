#include<bits/stdc++.h>
using namespace std;

// 参数:
//        numbers:     一个整数数组
//        length:      数组的长度
//        duplication: (输出) 数组中的一个重复的数字
// 返回值:
//        true  - 输入有效，并且数组中存在重复的数字
//        false - 输入无效，或者数组中没有重复的数字
bool duplicate(int numbers[], int length, int* duplication) {
	//nullptr是C++11中的空指针,这里是检查输入的有效性
	if(numbers == nullptr || length <= 0)
		return false;

	//这里也是检查输入数组是否符合值都在0~n-1之间这一要求
	for(int i = 0; i < length; ++i) {
		if(numbers[i] < 0 || numbers[i] > length - 1)
			return false;
	}

	//至此,合法性检查结束,遍历整个数组
	for(int i = 0; i < length; ++i) {
		//只要当前这个数和其下标不等,即m不为i,就一直循环
		while(numbers[i] != i) {
			//在交换之前,先判断一下它们是否重复(相等)
			if(numbers[i] == numbers[numbers[i]]) {
				//如果相等,就说明找到了这个重复元素,那么通过指针传出
				*duplication = numbers[i];
				//找到一个就结束该程序,因为题目就是只找任意一个
				return true;
			}

			//至此,说明判断不相等,要将它们交换以将当前的m放在正确的位置
			int temp = numbers[i];
			numbers[i] = numbers[temp];
			numbers[temp] = temp;
		}
		//如果当前这个数和下标相等,就去顺序地看下一个数
		//如果数组里根本没有i这个数,那么在这个位置上的不断交换一定可以发现重复的数
	}

	//整个数组遍历完都没有return,此时已经全部有序(从0到n-1),没有重复的数
	return false;
}

int main() {
	int a[7]= {3,1,2,0,2,5,3};
	int *p=new int();
	//boolalpha不会将bool值转为1/0输出 
	cout<<boolalpha<<duplicate(a,6,p)<<endl;
	if(nullptr==p)
		cout<<"没有重复的数"<<endl;
	else
		cout<<"重复的数字是"<<*p<<endl;
	delete p;
	return 0;
}
