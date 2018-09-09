#include<bits/stdc++.h>
using namespace std;

//泛型队列类
template <typename T> class CQueue {
	public:
		CQueue(void);
		~CQueue(void);

		//在队列末尾添加一个元素
		void appendTail(const T& node);

		//在队列头部删除一个元素
		T deleteHead();

	private:
		//提供两个STL栈
		stack<T> stack1;
		stack<T> stack2;
};

//构造函数
template <typename T> CQueue<T>::CQueue(void) {
}

//析构函数
template <typename T> CQueue<T>::~CQueue(void) {
}

//在逻辑队尾添加一个元素
template<typename T> void CQueue<T>::appendTail(const T& element) {
	stack1.push(element);//直接添加到A栈里
}

//在逻辑队头删除一个元素
template<typename T> T CQueue<T>::deleteHead() {
	//如果B栈里没有东西
	if(stack2.size()<= 0) {
		//对于A栈里的所有元素
		while(stack1.size()>0) {
			T& data = stack1.top();//这里是取栈顶元素,不然一会pop掉就没了
			stack1.pop();//弹出A栈的元素
			stack2.push(data);//压入B栈
		}
		//至此,A栈里的元素反向压入了B栈
	}

	//如果B栈里还是没有东西,这时A栈里也一定没有了,说明队列就是为空
	if(stack2.size() == 0)
		throw new exception();

	//否则从B栈中弹出栈顶元素,即是队列的头元素
	T head = stack2.top();//先取
	stack2.pop();//再弹

	return head;//返回刚刚删除的元素 
}

int main(int argc, char* argv[]) {
	//泛型擦除为char,建立自定义队列
	CQueue<char> queue;

	//在队列中添加元素
	queue.appendTail('a');
	queue.appendTail('b');
	queue.appendTail('c');
	
	try {
		//删除与测试
		char head = queue.deleteHead();
		cout<<"head="<<head<<endl;

		head = queue.deleteHead();
		cout<<"head="<<head<<endl;
	} catch(exception& exception) {
		cerr<<"queue is empty"<<endl;
	}
	return 0;
}
