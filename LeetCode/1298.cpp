class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        if (!n) return 0;

        vector<int> used(n, false);
        vector<int> have(n, false);

        queue<int> q;
        for (int box : initialBoxes) {
            if (status[box])
                q.push(box), used[box] = true;
            else
                have[box] = true;
        }

        int ans = 0;

        while (!q.empty()) {
            int box = q.front();
            q.pop();
            ans += candies[box];
            // key
            for (int k : keys[box]) {
                if (used[k])
                    continue;
                if (have[k])
                    q.push(k), used[k] = true;
                else
                    status[k] = true;
            }
            // box
            for (int b : containedBoxes[box]) {
                if (used[b])
                    continue;
                if (status[b])
                    q.push(b), used[b] = true;
                else
                    have[b] = true;
            }
        }

        return ans;
    }
};