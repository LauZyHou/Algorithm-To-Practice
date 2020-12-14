class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        int n = a.size();
        typedef pair<int, int> PII;
        // a - b
        vector<PII> r;
        for (int i = 0; i < n; i ++ ) {
            r.push_back({abs(b[i] + a[i]), i});
        }
        // sort
        sort(r.begin(), r.end());
        // for (int i = 0; i < n; i ++ )
        //     cout << r[i].first << ' ' << r[i].second << endl;
        int ra = 0, rb = 0;
        for (int i = n - 1; i >= 0; i -= 2 )
            ra += a[r[i].second];
        for (int i = n - 2; i >= 0; i -= 2)
            rb += b[r[i].second];
        if (ra > rb)
            return 1;
        if (rb > ra)
            return -1;
        return 0;
    }
};