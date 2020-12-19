class Solution {
public:
    int mon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int dayOfYear(string date) {
        int y = stoi(date.substr(0, 4)), m = stoi(date.substr(5, 2)), d = stoi(date.substr(8, 2));
        int res = 0;
        for (int i = 0; i < m - 1; i ++ ) {
            res += mon[i];
            if (i == 1 && (y % 4 == 0 && y % 100 || y % 400 == 0))
                res += 1;
        }
        return res + d;
    }
};