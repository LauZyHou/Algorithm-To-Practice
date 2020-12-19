class Solution {
public:
    vector<string> mon = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    unordered_map<string, int> mp;

    Solution() {
        for (int i = 0; i < 12; i ++ ) {
            mp[mon[i]] = i + 1;
        }
    }

    string reformatDate(string date) {
        int d = 0, m = 0, y = 0;
        int i = 0;
        while (isdigit(date[i]))
            d = d * 10 + date[i ++ ] - '0';

        while (date[i] != ' ') i ++ ;
        m = mp[date.substr(i + 1, 3)];

        i += 5;
        while (i < date.size())
            y = y * 10 + date[i ++ ] - '0';
        return to_string(y) + "-" + (m < 10 ? "0" : "") + to_string(m) + "-" + (d < 10 ? "0" : "") + to_string(d);
    }
};