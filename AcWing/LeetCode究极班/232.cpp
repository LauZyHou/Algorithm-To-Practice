class MyQueue {
public:
    stack<int> s, w;

    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while (s.size() > 1)
            w.push(s.top()), s.pop();
        int r = s.top();
        s.pop();
        while (w.size())
            s.push(w.top()), w.pop();
        return r;
    }
    
    /** Get the front element. */
    int peek() {
        while (s.size() > 1)
            w.push(s.top()), s.pop();
        int r = s.top();
        while (w.size())
            s.push(w.top()), w.pop();
        return r;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty() && w.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */