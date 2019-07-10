class KthLargest {
public:
	priority_queue<int>* pq = nullptr;
	int k;
    KthLargest(int k, vector<int>& nums) {
        if(pq) {
			delete pq;
			pq = nullptr;
		}
		pq = new priority_queue<int>();
		this->k = k;
		int len = nums.size();
		for(int i=0;i<len;i++)
			pq->push(-1*nums[i]);
    }
    
    int add(int val) {
        pq->push(-1*val);
		//把更多的最小元素弹出来,只保留k个元素
		int nowlen = pq->size();
		for(int i=k;i<nowlen;i++)
			pq->pop();
		return -1*pq->top();//k个元素的最小堆堆顶元素
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */