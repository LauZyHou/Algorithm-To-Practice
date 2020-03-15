class CustomStack {
private:
    int* v = nullptr;
    int size = 0;
    int p = 0;
public:
    CustomStack(int maxSize) {
        size = maxSize;
        v = new int[size];
    }
    
    void push(int x) {
        if(p<size)
            v[p++] = x;
    }
    
    int pop() {
        if(p==0)
            return -1;
        return v[--p];
    }
    
    void increment(int k, int val) {
        int t = min(k,p);
        for(int i=0;i<t;i++)
            v[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */