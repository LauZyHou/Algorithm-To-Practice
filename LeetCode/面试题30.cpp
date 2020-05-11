class MinStack {
private:
    stack<int> st;
    stack<int> mst;
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        st.push(x);
        if(mst.empty() || mst.top()>x)
            mst.push(x);
        else
            mst.push(mst.top());
    }
    
    void pop() {
        if(st.empty())
            return;
        st.pop();
        mst.pop();
    }
    
    int top() {
        if(st.empty())
            return -1;
        return st.top();
    }
    
    int min() {
        if(st.empty())
            return -1;
        return mst.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */