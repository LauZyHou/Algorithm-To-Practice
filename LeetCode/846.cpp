class Solution {
public:
    bool isNStraightHand(vector<int>& a, int k) {
        int n = a.size();
        if (n % k) return false;
        multiset<int> m;
        unordered_map<int, int> h;
        for (auto x: a) {
            m.insert(x);
            h[x] ++ ;
        }
        n /= k;
        while (n -- ) {
            // 最小值
            int x = *m.begin();
            for (int i = 0; i < k; i ++ ) {
                if (!h[x + i]) return false;
                m.erase(m.find(x + i));
                h[x + i] -- ;
            }
        }
        return true;
    }
};