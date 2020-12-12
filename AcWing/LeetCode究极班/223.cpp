typedef long long LL;

class Solution {
public:
    int computeArea(LL A, LL B, LL C, LL D, LL E, LL F, LL G, LL H) {
        LL x = max(0ll, min(C, G) - max(A, E));
        LL y = max(0ll, min(D, H) - max(B, F));
        return (C - A) * (D - B) - x * y + (G - E) * (H - F);
    }
};