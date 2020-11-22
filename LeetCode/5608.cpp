typedef pair<int, int> PII;

class Solution {
public:
    bool static cmp(PII& a, PII& b) {
        return a.first - a.second < b.first - b.second;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();
        int sum = 0;        
        
        
        vector<PII> prs;
        for (auto& t: tasks) {
            sum += t[0];
            prs.push_back({t[1], t[0]});
        }
        sort(prs.begin(), prs.end(), cmp);
        int need = 0;
        int cur = sum;
        for (int i = n - 1; i >= 0; i -- ) {
            if (prs[i].first > cur)
                need = max(need, prs[i].first - cur);
            cur -= prs[i].second;
        }
        return sum + need;
    }
};