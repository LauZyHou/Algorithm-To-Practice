class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int> >  sml; // 小顶堆，存较大的那些值
    priority_queue<int, vector<int>, less<int> > big; // 大顶堆，存较小的那些值

public:
    /** initialize your data structure here. */
    MedianFinder() {
        sml = priority_queue<int, vector<int>, greater<int> >();
        big = priority_queue<int, vector<int>, less<int> >();
    }
    
    void addNum(int num) {
        if (sml.size() == big.size()) {
            // 加到sml里
            big.push(num);
            int val = big.top();
            big.pop();
            sml.push(val);
        }
        else {
            // 加到big里
            sml.push(num);
            int val = sml.top();
            sml.pop();
            big.push(val);
        }
    }
    
    double findMedian() {
        if (sml.size() == big.size()) {
            double v1 = sml.top();
            double v2 = big.top();
            return (v1 + v2) / 2;
        }
        else {
            return sml.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */