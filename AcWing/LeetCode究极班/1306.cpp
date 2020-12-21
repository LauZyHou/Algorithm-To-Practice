class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        vector<bool> visit(arr.size(), false);
        q.push(start);
        while (q.size()) {
            int t = q.front();
            q.pop();
            visit[t] = true;
            if (!arr[t]) return true;
            if (t - arr[t] >= 0 && !visit[t - arr[t]]) q.push(t - arr[t]);
            if (t + arr[t] < arr.size() && !visit[t + arr[t]]) q.push(t + arr[t]);
        }
        return false;
    }
};