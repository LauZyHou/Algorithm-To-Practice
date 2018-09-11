#pragma once		//由编译器保证只包含一次该文件 

#include <stack>	//STL栈 
#include <assert.h>	//断言:判断逻辑表达式的真假 

//泛型类:包含Min函数的栈 
template <typename T> class StackWithMin {
	public:
		StackWithMin() {}//构造器 
		//这里定义成虚析构函数,则用本基类创建的派生类对象析构时
		//能正常调用派生类的析构函数,再来调用基类析构函数
		//而不是只调用基类的析构函数 
		//若一个类不可能作为基类,不要将虚构函数虚化
		//因为有了虚函数就会为类增加一个虚函数表,使对象的体积翻倍 
		virtual ~StackWithMin() {} 

		T& top();//取栈顶元素
		//const T&表示返回的T类型引用是常引用,不可修改
		//const放在成员函数后面,让该函数的权限为只读
		//也就是说它没法去改变non-static成员变量的值
		//同时,如果一个对象为const,它只有权利调用const成员函数以保证不修改non-static成员 
		const T& top() const;

		void push(const T& value);//入栈 
		void pop();//出栈 

		const T& min() const;//获取栈中最小值 

		bool empty() const;//判断栈是否为空 
		size_t size() const;//获取栈的大小 

	private:
		std::stack<T>   m_data;//数据栈,存放栈的所有元素
		std::stack<T>   m_min;//辅助栈,同步数据栈的最小元素状态 
};

//入栈 
template <typename T> void StackWithMin<T>::push(const T& value) {
	//把新元素添加到辅助栈
	m_data.push(value);

	//当新元素比之前的最小元素小时
	//压入这个元素使得当前栈中的最小元素"状态"改变了 
	if(m_min.size() == 0 || value < m_min.top())
		m_min.push(value);//把新元素插入辅助栈里
	else//否则
		m_min.push(m_min.top());//把之前的最小元素重复插入辅助栈里
}

//出栈 
template <typename T> void StackWithMin<T>::pop() {
	//断言,调用出栈时两个栈的元素一定都是>0的
	//如果其值为假(即为0),那么它先向stderr打印一条出错信息
	//然后通过调用abort来终止程序运行
	assert(m_data.size() > 0 && m_min.size() > 0);
	//两个栈同步出 
	m_data.pop();
	m_min.pop();
}

//取最小 
template <typename T> const T& StackWithMin<T>::min() const {
	assert(m_data.size() > 0 && m_min.size() > 0);//取最小时栈内也一定有元素 
	//辅助栈栈顶即是当前栈状态下的栈内最小元素 
	return m_min.top();
}

/*以下都是直接调用STL栈的操作即可*/

template <typename T> T& StackWithMin<T>::top() {
	return m_data.top();
}

template <typename T> const T& StackWithMin<T>::top() const {
	return m_data.top();
}

template <typename T> bool StackWithMin<T>::empty() const {
	return m_data.empty();
}

template <typename T> size_t StackWithMin<T>::size() const {
	return m_data.size();
}
