class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
		for(auto n:nums) {
			if(pq.size()==k) {
				if(n<pq.top())
					continue;
				else
					pq.pop();
			}
			pq.push(n);
		}
		return pq.top();
    }
};