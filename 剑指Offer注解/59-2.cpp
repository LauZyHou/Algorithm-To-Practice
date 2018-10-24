#include<bits/stdc++.h>
using namespace std;

//带max函数的队列模板类 
template<typename T> class QueueWithMax {
	private:
		//这个自定义队列的元素结点结构体
		struct InternalData { 
			T number;//元素的值,泛型类型 
			int index;//插入时被赋予的下标 
		};
		deque<InternalData> data;//存队列实际内容的双端队列 
		deque<InternalData> maximums;//存最大值的双端队列 
		int currentIndex;//接下来要插入元素应该赋予的下标 

	public:
		//构造器 
		QueueWithMax() : currentIndex(0) {//初始化下标值为0 
		}

		//入队,相当于上一题里面滑动窗口滑入一个数字 
		void push_back(T number) {
			//和老数字比较,把双端队列里不比他大的老元素都删掉 
			while(!maximums.empty() && number >= maximums.back().number)
				maximums.pop_back();
 
			InternalData internalData = { number, currentIndex };//创建元素结点
			data.push_back(internalData);//进入存元素的队列 
			maximums.push_back(internalData);//也进入最大值队列 

			++currentIndex;//id自增1,用来给下一个插入的元素用 
		}

		//出队,相当于滑出窗口,不过这里可以视为窗口从左侧内陷1造成的 
		void pop_front() {
			if(maximums.empty())//队列为空不能出队 
				throw new exception();//queue is empty
			
			//这个就比上一题的滑出容易多了,直接判断是不是当前最大 
			if(maximums.front().index == data.front().index)
				maximums.pop_front();//如果是,就把那个当前最大也拿掉(从队头) 

			data.pop_front();//出队 
		}

		//获取最大值
		//尾接const表示成员函数隐含传入的this指针为const指针
		//即在这个成员函数内不能修改非mutable成员 
		T max() const {
			if(maximums.empty())//为空就没有最大值 
				throw new exception();//queue is empty
			//存最大值的双端队列的队头元素的number域 
			return maximums.front().number;
		}
};

int main() {
	QueueWithMax<int> queue;
	queue.push_back(2);
	cout<<queue.max()<<endl;//2
	queue.push_back(4);
	cout<<queue.max()<<endl;//4
	queue.push_back(3);
	cout<<queue.max()<<endl;//4
	queue.push_back(2);
	cout<<queue.max()<<endl;//4
	queue.pop_front();
	cout<<queue.max()<<endl;//4
	queue.pop_front();
	cout<<queue.max()<<endl;//3
	return 0;
}
