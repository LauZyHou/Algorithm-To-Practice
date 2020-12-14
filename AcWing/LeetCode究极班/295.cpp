class MedianFinder {
public:
    // 小根堆存较大一侧的数据，在对顶堆概念图里是上边的堆
    priority_queue<int, vector<int>, greater<int>> up;
    // 大根堆存较大一侧的数据，在对顶堆概念图里是下边的堆
    priority_queue<int> down;

    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int t) {
        // 特判一下，如果下面是空的，或者当前要插入的t是不超过下面的堆顶元素的，就插入下面
        // 下面是空的为什么插入下面？因为要满足下面和上面一样多或者多1这个条件
        if (down.empty() || t <= down.top()) {
            down.push(t);
            // 插入完之后如果不满足size要求就移过去一个
            if (down.size() > up.size() + 1) {
                up.push(down.top());
                down.pop();
            }
        }
        // 否则将当前元素插入到上面
        else {
            up.push(t);
            // 插入完成之后如果不满足size要求就移过去一个
            if (up.size() > down.size()) {
                down.push(up.top());
                up.pop();
            }
        }
    }
    
    double findMedian() {
        // 如果总元素个数是奇数，那么就返回下面的
        if ((up.size() + down.size()) & 1)
            return down.top();
        return (up.top() + down.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */