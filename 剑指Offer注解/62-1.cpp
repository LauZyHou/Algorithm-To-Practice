#include<bits/stdc++.h>
using namespace std;

//0~n-1,每次删除第m个数字,返回最后剩下的数字 
int LastRemaining_Solution1(unsigned int n, unsigned int m) {
	if(n < 1 || m < 1)//n和m都应为正 
		return -1;

	unsigned int i = 0;//游标 

	list<int> numbers;//存数字的链表 
	for(i = 0; i < n; ++ i)//从数组中存到这个链表里 
		numbers.push_back(i);

	list<int>::iterator current = numbers.begin();//迭代器从链表头开始 
	while(numbers.size() > 1) {//链表中至少留一个元素 
		for(int i = 1; i < m; ++ i) {//"第m个"即是要向后走m-1步 
			current ++;
			if(current == numbers.end())//走出尾(end没存数字) 
				current = numbers.begin();//就回到头部 
		}

		list<int>::iterator next = ++ current;//要删除数字的下一个数字 
		if(next == numbers.end())//还是,模拟环形结构 
			next = numbers.begin();

		-- current;//迭代器回到这个要删除的数字 
		numbers.erase(current);//将它删除 
		current = next;//迭代器指向刚刚删除数字的下一个数字 
	}//继续重复这个过程,直到链表中只剩下一个数字为止  
	return *(current);//返回这个唯一的数字 
}

int main() {
	cout<<LastRemaining_Solution1(4000,997)<<endl;//1027
	return 0;
}
