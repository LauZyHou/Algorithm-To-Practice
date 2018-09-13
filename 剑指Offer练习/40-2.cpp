#include<bits/stdc++.h>
#include "../Utilities/Array.h"
using namespace std;

//typedef用来声明别名:"typedef 复杂的东西 别名;"
//greater表示内置类型从大到小排序,即第一个元素一定是最大的
//set和multiset会根据特定的排序原则将元素排序,这里即模拟了最大堆
typedef multiset<int, greater<int> >            intSet;
typedef multiset<int, greater<int> >::iterator  setIterator;

//传入数组,取最小的k个元素的multiset容器,k的值
//找到数组中最小的k个元素,放入容器中供调用者使用
void GetLeastNumbers_Solution2(const vector<int>& data, intSet& leastNumbers, int k) {
	leastNumbers.clear();//清空容器
	//检查输入合法性
	if(k < 1 || data.size() < k)
		return;
	//从数组前面开始
	vector<int>::const_iterator iter = data.begin();
	for(; iter != data.end(); ++ iter) {//向后遍历整个数组
		if((leastNumbers.size()) < k)//如果容器还没满
			leastNumbers.insert(*iter);//直接插入容器中
		else {//如果容器已经满了
			//取排序multiset的第一个元素,即逻辑最大堆的堆顶
			setIterator iterGreatest = leastNumbers.begin();
			//如果当前这个数比最大堆堆顶还小
			if(*iter < *(leastNumbers.begin())) {
				leastNumbers.erase(iterGreatest);//把堆顶移出去
				leastNumbers.insert(*iter);//把它放进来
			}
		}
	}
}

int main() {
	int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
	//写入vector数组 
	vector<int> vectorData;
	for(int i = 0; i < 8; ++ i)
		vectorData.push_back(data[i]);
	//multiset容器 
	intSet leastNumbers;
	GetLeastNumbers_Solution2(vectorData,leastNumbers,4);
	//在这个容器里是从大到小有序的,使用真的最大堆时不能保证有序 
	for(setIterator iter = leastNumbers.begin(); iter != leastNumbers.end(); ++iter)
		cout<<*iter<<"\t";
	return 0;
}
