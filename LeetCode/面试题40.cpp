class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ans(k);
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto& x:arr)
            pq.push(x);
        int i=0;
        for (int i = 0; i < k; i++)
        {
            ans[i] = pq.top();
            pq.pop();
        }
        return ans;
    }
};