#include<iostream>
#include<vector>
using namespace std;

//vector练习 

int main(){
	vector<int> v1;
	vector<int> v2(5);//初始大小
	cout<<v1.size()<<"\t"<<v2.size()<<endl; 
	vector<int> v3(3,4);//初始大小3,里面每个都是4
	
	for(int i=0;i<3;i++)
		cout<<v3[i];
	cout<<endl;
	
	vector<int> v4(v3.begin(),v3.begin()+1);//用v3的一部分构造v4 
	cout<<v4.size()<<endl;
	
	int a[]={1,2,3,4,5};
	vector<int> v5(a+1,a+3);//用子数组构造v5 
	
	//size()是真实大小,capacity()是允许的大小
	//resize()修改前者,reserve()修改后者(但空间是野的)
	cout<<v5.size()<<"\t"<<v5.capacity()<<endl;
	v5.resize(10);
	cout<<v5.size()<<"\t"<<v5.capacity()<<endl;//capacity会随着size变大超出capacity而变得一样大 
	v5.reserve(20);
	cout<<v5.size()<<"\t"<<v5.capacity()<<endl;
	
	vector<int> v6(a+1,a+4);//不包括a+4这个位置 
	
	v6.push_back(6);//尾插
	v6.erase(v6.begin()+2);//任意位置删除(传入迭代器)
	for(vector<int>::const_iterator it=v6.cbegin();it!=v6.cend();it++)//带c是const的 
		cout<<*it<<"\t";
	cout<<"\n";
	//2,3,6
		
	v6.pop_back();//尾删
	v6.insert(v6.cbegin()+1,8);//任意位置插入 
	for(vector<int>::const_iterator it=v6.cbegin();it!=v6.cend();it++) 
		cout<<*it<<"\t";
	cout<<"\n";
	
	//2,8,3
	
	v6.swap(v3);//v6和v3相交换
	for(vector<int>::const_iterator it=v6.cbegin();it!=v6.cend();it++) 
		cout<<*it<<"\t";
	cout<<"\n";
	
	//访问第一个和最后一个元素
	cout<<v3.front()<<"\t"<<v3.back()<<endl;
	
	//清空
	v6.clear();
	cout<<v6.size()<<"\t"<<v6.capacity()<<endl;//capacity不变 
	return 0;
}
