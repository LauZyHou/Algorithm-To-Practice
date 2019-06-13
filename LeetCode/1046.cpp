class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
		priority_queue<int> pq(stones.begin(),stones.end());
		while(pq.size()>1) {//至少有2个元素
			int y = pq.top();
			pq.pop();
			int x = pq.top();
			pq.pop();
			int r = abs(y-x);
			if(r)
				pq.push(r);
		}
		return pq.empty() ? 0 : pq.top();
    }
};