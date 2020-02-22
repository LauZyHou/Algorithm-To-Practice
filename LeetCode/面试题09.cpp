class CQueue {
private:
    stack<int>* a = nullptr;
    stack<int>* b = nullptr;
public:
    CQueue() {
        a = new stack<int>();
        b = new stack<int>();
    }
    
    void appendTail(int value) {
        a->push(value);
    }
    
    int deleteHead() {
        while(a->empty()==false){
            int t = a->top();
            a->pop();
            b->push(t);
        }
        if(b->empty()) // 这里要检查一下b是不是还是空的
            return -1;
        int ret = b->top();
        b->pop();
        while(b->empty()==false){
            int t = b->top();
            b->pop();
            a->push(t);
        }
        return ret;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */