const int N = 1e5 + 10;

class Solution {
private:
    int h[N];
    int sz;
    void down(int u) {
        int t = u;
        if (u * 2 <= sz && h[u * 2] < h[t])
            t = u * 2;
        if (u * 2 + 1 <= sz && h[u * 2 + 1] < h[t])
            t = u * 2 + 1;
        if (t != u) {
            swap(h[t], h[u]);
            down(t);
        }
    }

public:
    vector<int> smallestK(vector<int>& arr, int k) {
        sz = arr.size();
        for (int i = 0; i < sz; i ++)
            h[i + 1] = arr[i];
        for (int i = sz / 2; i; i --)
            down(i);
        
        vector<int> ans;
        while (k --) {
            ans.push_back(h[1]);
            h[1] = h[sz];
            sz --;
            down(1);
        }
        return ans;
    }
};