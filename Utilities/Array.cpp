#include <stdlib.h>
#include "Array.h"
#include <exception>

//在min和max之间随机找一个数 
int RandomInRange(int min, int max) {
	//即随机数对距离取整,再加上最小数使其落在这个范围 
	int random = rand() % (max - min + 1) + min;
	return random;
}

//交换两指针所对应的值 
void Swap(int* num1, int* num2) {
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

//在start和end中随机找一个数,在长为length的data数组中以此下标为界
//划分整个数组,使比它(所对应的数)小的数都在其左边,>=它的在右边 
int Partition(int data[], int length, int start, int end) {
	//输入合法性检查 
	if(data == nullptr || length <= 0 || start < 0 || end >= length)
		throw new std::exception();
	//随机取该范围内的一个划分点 
	int index = RandomInRange(start, end);
	//将其和最后一个位置的数进行交换(因为从边界的位置开始划分比较方便)
	Swap(&data[index], &data[end]);
	
	/*接下来作者的操作需要画图理解!*/

	int small = start - 1;//这只是方面后面在循环里都做++ 
	//从前到后遍历除最后位置之外的所有位置 
	for(index = start; index < end; ++ index) {
		//如果发现比分隔数小的数字 
		if(data[index] < data[end]) {
			++ small;//这时small才+1
			//注意index随着循环总是+1,但是small遇到一些>=分隔数的数字时
			//就会暂且落后一个身位,在>=分隔数的数字前面
			//当下一次遇到比分隔数小的数字时,就会执行++small踩上来 
			if(small != index)//这里去除无用操作,相等时即指向同一个比分隔数小的数字 
				//交换两个数,使得让small指针受阻的第一个>=分隔数的数字换过来 
				Swap(&data[index], &data[small]);//取而代之的是一个比分隔数小的数字 
			//每次交换完成之后,相当于为small指针破开了一个向前走的阻碍
			//这个阻碍就是>=分隔数的数字
		}
		//因为这个遍历会遍历完整个(除最后一个分隔数之外)数组
		//相当于去拿后面的小数字去砸阻碍small的大石头,能砸掉多少是多少
		//整个遍历完成后,small前面仍然会有(也可以没有)大石头(指>=分隔数的数字)
		//但是这些石头里不会再夹杂任何比分隔数小的数字了 
	}
	
	//所以,至此,数组里的情况是[小..小(small)][石..石(index)][分隔数(end)] 
	//(当然也可以没有小于分隔数的数字,或者没有>=分隔数的数字,这些情况都能通过) 
	//现在,small指向最后一个比分割数字小的数字,index指向分隔数前一个数字 

	++ small;//small向前走一步踩在接下来第一个石头上 
	Swap(&data[small], &data[end]);//将其和最后的分隔数交换 
	
	//现在数组情况:[小..小][分隔数(small)][石..石(index)石(end)]

	return small;//返回分隔数所在位置下标 
}
