class MyStack {
private:
	queue<int> q;
	//将队列的前n-1个元素放入队列的尾部
	void change(){
		int len = q.size();
		if(!len)
			return;
		len--;
		while(len--){
			int x = q.front();
			q.pop();
			q.push(x);
		}
	}
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        this->change();
		int x = q.front();
		q.pop();
		return x;
    }
    
    /** Get the top element. */
    int top() {
        int x = this->pop();
		q.push(x);
		return x;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */