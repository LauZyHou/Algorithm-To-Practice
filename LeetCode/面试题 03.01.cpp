class TripleInOne {
private:
    int pointer[3] = {0,0,0};
    int* val = nullptr;
    int size;
public:
    TripleInOne(int stackSize) {
        val = new int[stackSize*3];
        size = stackSize;
    }
    
    void push(int stackNum, int value) {
        if(3*pointer[stackNum]+stackNum>=size*3)
            return;
        val[3*pointer[stackNum]+stackNum] = value;
        pointer[stackNum]++;
    }
    
    int pop(int stackNum) {
        if(pointer[stackNum]==0)
            return -1;
        int ans = peek(stackNum);
        pointer[stackNum]--;
        return ans;
    }
    
    int peek(int stackNum) {
        if(pointer[stackNum]==0)
            return -1;
        return val[3*(pointer[stackNum]-1)+stackNum];
    }
    
    bool isEmpty(int stackNum) {
        return pointer[stackNum]==0;
    }
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */