class Solution {
public:
    int compareVersion(string v1, string v2) {
        int n = v1.size(), m = v2.size();
        for (int i = 0, j = 0; i < n || j < m; ) {
            int a = i, b = j;
            while (a < n && v1[a] != '.') a ++;
            while (b < m && v2[b] != '.') b ++;
            int x = a == i ? 0 : stoi(v1.substr(i, a - i));
            int y = b == j ? 0 : stoi(v2.substr(j ,b - j));
            if (x > y)
                return 1;
            if (x < y)
                return -1;
            i = a + 1, j = b + 1;
        }
        return 0;
    }
};