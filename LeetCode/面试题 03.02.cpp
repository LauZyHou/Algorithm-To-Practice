class MinStack {
private:
    stack<int> stMin;
    stack<int> stVal;
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        stVal.push(x);
        if(stMin.empty() || stMin.top()>x)
            stMin.push(x);
        else
            stMin.push(stMin.top());
    }
    
    void pop() {
        stVal.pop();
        stMin.pop();
    }
    
    int top() {
        return stVal.top();
    }
    
    int getMin() {
        return stMin.top();
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