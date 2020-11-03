class MinStack {
public:
    stack<int> stk, f;

    /** initialize your data structure here. */
    MinStack() {
        stk = stack<int>();
        f = stack<int>();    
    }
    
    void push(int x) {
        stk.push(x);
        if (f.empty() || x <= f.top())
            f.push(x);
    }
    
    void pop() {
        if (stk.top() <= f.top())
            f.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return f.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */