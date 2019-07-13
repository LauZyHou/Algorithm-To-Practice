class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& v) {
		int len = v.size();
        priority_queue<int> pq;
		for(int t:v) {
			pq.push(t);
		}

		//队头表示牌底,队尾表示牌顶
		queue<int> q;
		while(pq.empty()==false) {
			int t = pq.top();//当前最大
			pq.pop();
			q.push(t);
			
			//注意,全放好之后不会再多做一次下面的拿出来放到最顶上的过程
			if(pq.empty())
				break;
			
			int hd = q.front();
			q.pop();
			q.push(hd);
		}
		vector<int> ans(len);
		for(int i=len-1;i>=0;i--) {
			ans[i] = q.front();
			q.pop();
		}
		return ans;
    }
};