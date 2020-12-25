class MyCircularQueue {
public:
    int hh = 0, tt = 0; // 队头和队尾
    vector<int> q; // 数组模拟循环队列

    MyCircularQueue(int k) {
        q.resize(k + 1); // 多开一个位置
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        q[tt ++ ] = value; // 入队顺时针走队尾
        if (tt == q.size()) tt = 0; // 走出最后就回到0
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        // 删除队头
        hh ++ ;
        if (hh == q.size()) hh = 0;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return q[hh]; // 返回队头
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        // 队尾指针tt不存元素，注意其上一个位置才是队尾
        int t = tt - 1;
        if (t < 0) t = q.size() - 1;
        return q[t];
    }
    
    bool isEmpty() {
        // 两个指针在同一个位置时候为空
        return tt == hh;
    }
    
    bool isFull() {
        // 队尾指针的下一个位置是队头时候为满
        return (tt + 1) % q.size() == hh;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */