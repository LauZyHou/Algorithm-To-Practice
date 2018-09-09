#include<bits/stdc++.h>
using namespace std;

// 参数:
//        numbers:     一个整数数组
//        length:      数组的长度
//        start:       范围的起始值
//        end:         范围的终止值
// 返回值:
//        数组中在指定范围内的数字的数目
int countRange(const int* numbers, int length, int start, int end)
{
	//检查输入数组合法性 
    if(numbers == nullptr || length <= 0)
        return 0;

	//统计并返回数组中在指定范围内的数字个数 
    int count = 0;
    for(int i = 0; i < length; i++)
        if(numbers[i] >= start && numbers[i] <= end)
            ++count;
    return count;
}

// 参数:
//        numbers:     一个整数数组
//        length:      数组的长度
// 返回值:             
//        正数  - 输入有效，并且数组中存在重复的数字，返回值为重复的数字
//        负数  - 输入无效，或者数组中没有重复的数字
int getDuplication(const int* numbers, int length)
{
	//检查输入数组合法性 
    if(numbers == nullptr || length <= 0)
        return -1;

	//初始考察的区间范围是0~n-1之间 
    int start = 0;
    int end = length - 1;
    //当这个区间还正确存在 
    while(end >= start)
    {
    	//取区间的中间数,将其划分成两个子区间 
        int middle = ((end - start) >> 1) + start;
        cout<<"middle="<<middle<<"\n";
        //判断一下数组中落在前一半区间中的数的个数 
        int count = countRange(numbers, length, start, middle);
        
        //终止条件:如果这个区间已经收缩到仅剩一个数 
        if(end == start)
        {
        	//这时start=middle=end,刚刚统计的也就是数组中该数的个数
            if(count > 1)//如果该数个数>1
                return start;//那么所要求的重复数就是它 
            else//否则,没有找到重复的数 
                break;//直接退出寻找 
        }

		//后面这部分是没有走[终止条件]时都会运行的
		
		//如果数组中落在前一半区间的数的个数超过了区间长度
		//说明至少存在一个该区间的数,在数组中是重复出现了的 
        if(count > (middle - start + 1))
            end = middle;//因此将考察的范围缩小到这前半个区间上 
        else//否则 
            start = middle + 1;//将考察的范围缩小到后半个区间上 
    }
	//运行至此,没有找到重复的数
	//该算法不能保证真的没有重复的数,试想数组仅0113在0~3的区间上可被跳过 
	return -1;
}


int main(){
	//从0~3区间内,数组中有2,2,3,3正好4个
	//从4~7区间内,数组中有4,5,6,7正好4个
	//识别不出这种情况下的重复数字
	//这组数据在书上从1~n-1的情况下是能识别出来的 
	int a[8]={2,3,5,4,3,2,6,7};
	cout<<getDuplication(a,8)<<"--------------------"<<endl;
	//下面这组数据也找不出重复的1 
	int b[8]={0,1,1,3,4,5,6,7};
	cout<<getDuplication(b,8)<<"--------------------"<<endl;
	//这种数据就能找出来
	int c[7]={3,1,2,0,2,5,3};
	cout<<getDuplication(c,7)<<"--------------------"<<endl;
	return 0;
}

