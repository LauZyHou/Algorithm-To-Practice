class MyQueue {
private:
	stack<int> a;
	stack<int> b;

public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        a.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x = this->peek();
		b.pop();
		return x;
    }
    
    /** Get the front element. */
    int peek() {
        if(b.empty()){
			while(!a.empty()){
				int x = a.top();
				b.push(x);
				a.pop();
			}
		}
		int x = b.top();
		return x;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return b.empty() && a.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */