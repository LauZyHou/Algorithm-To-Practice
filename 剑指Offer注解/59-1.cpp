#include<bits/stdc++.h>
using namespace std;

//输入数组和窗口大小,输出滑动窗口的最大值数组 
vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
	vector<int> maxInWindows;//滑动窗口的最大值数组 
	if(num.size() >= size && size >= 1) {//数组要比窗口大,窗口要不少于1 
		deque<int> index;//双端队列,用于记录窗口中可能的最大值所在数组中下标 

		//窗口初始状态下会覆盖数组的前size个位置 
		for(unsigned int i = 0; i < size; ++i) {
			//如果新的这个数字比窗口中的一些数字大
			//注意是比尾部的一些数字大
			//比如[4213]...,先进4;
			//遇到2比尾部4小但在滑动中可能成为最大,尾插2
			//遇到1比尾部2小但在滑动中可能成为最大,尾插1
			//遇到3比尾部1大,因为只要1还在窗口里3一定在
			//所以一定轮不到1做最大,把1尾删
			//同理,接着遇到2,把2尾删
			//接着遇到4,3比4小,4划出去了3可能还是最大 
			while(!index.empty() && num[i] >= num[index.back()])//等于的时候也删不影响,相当于用大的游标了 
				index.pop_back();
			//尾部插入是一定会插入的,就像前面的分析过程
			//因为不可能根据前面的老数字判断年轻的自己没有成为最大的可能
			//只可能在下次for循环中看到更年轻且更大的数字,才能断定自己没有可能做最大了 
			index.push_back(i);
		}
		
		//前面初始化判断过了0~size-1位置,接下来是滑动过程
		//即从size位置到最后的num.size()-1数组尾
		for(unsigned int i = size; i < num.size(); ++i) {
			//在每次滑动之前写入当前窗口的最大值
			//即下标为index队头的数组元素 
			maxInWindows.push_back(num[index.front()]);
			
			//窗口向前滑动(没有任何代码),表现在接下来要使用i的值了
			//或者可以说for里的++i就是窗口向前滑动1
			//但这样也不好理解上一句是"滑动之前写入"
			
			//滑动后,用同样的逻辑调整存最大值下标的双端队列 
			while(!index.empty() && num[i] >= num[index.back()])
				index.pop_back();
			//如果当前双端队列的最大值下标不超过当前下标减去滑动窗口大小 
			if(!index.empty() && index.front() <= (int) (i - size))
				index.pop_front();//就说明这个最大值刚好滑出来了,将其删除 
			
			//和前面类似地,将当前位置的下标压入
			//只有后续的年轻数字才有淘汰自己的资格 
			index.push_back(i);
		}
		//最后一次滑动还没写入,将其最大值写入 
		maxInWindows.push_back(num[index.front()]);
	}
	return maxInWindows;//返回滑动窗口的最大值数组 
}

int main() {
	int num[] = { 2, 3, 4, 2, 6, 2, 5, 1 };
	vector<int> vPut;
	for(unsigned int i=0;i<sizeof(num)/sizeof(int);i++){
		vPut.push_back(num[i]);
	}
	vector<int> vGet=maxInWindows(vPut,3);
	for(vector<int>::const_iterator cit=vGet.cbegin();cit!=vGet.cend();cit++){
		cout<<*cit<<"\t";//4 4 6 6 6 5
	}
	return 0;
}
