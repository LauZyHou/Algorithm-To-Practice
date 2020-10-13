class MedianFinder {
private:
    // 存小数的最大堆
    priority_queue<int, vector<int>, less<int> > sml;
    // 存大数的最小堆
    priority_queue<int, vector<int>, greater<int> > big;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        sml = priority_queue<int, vector<int>, less<int> >();
        big = priority_queue<int, vector<int>, greater<int> >();
    }
    
    void addNum(int num) {
        if (sml.size() == big.size()) {
            big.push(num);
            int val = big.top();
            big.pop();
            sml.push(val);
        }
        else {
            sml.push(num);
            int val = sml.top();
            sml.pop();
            big.push(val);
        }
    }
    
    double findMedian() {
        if (big.size() == sml.size()) {
            double vb = big.top();
            double vs = sml.top();
            return (vb + vs) / 2;
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