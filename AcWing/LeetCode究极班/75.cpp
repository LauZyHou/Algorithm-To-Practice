class Solution {
public:
    void sortColors(vector<int>& a) {
        for (int i = 0, j = 0, k = a.size() - 1; i <= k; ) {
            if (a[i] == 0) {
                swap(a[i], a[j]);
                i ++, j ++;
            }
            else if (a[i] == 1) {
                i ++;
            }
            else { // 2
                swap(a[i], a[k]);
                k --;
            }
        }
    }
};