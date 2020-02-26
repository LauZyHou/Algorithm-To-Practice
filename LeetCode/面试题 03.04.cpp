class MyQueue {
private:
    stack<int>* s1 = nullptr;
    stack<int>* s2 = nullptr;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        s1 = new stack<int>();
        s2 = new stack<int>();
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        //倒回去
        while(!s2->empty()) {
            int t = s2->top();
            s2->pop();
            s1->push(t);
        }
        s1->push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(!s1->empty()) {
            int t = s1->top();
            s1->pop();
            s2->push(t);
        }
        if(s2->empty()) {
            return -1;
        }
        int ret = s2->top();
        s2->pop();
        // 这里先不把s2倒回去,因为可能连续pop,在需要push时候再倒回去
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        int ret = this->pop();
        s2->push(ret);
        return ret;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s2->empty() && s1->empty();
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