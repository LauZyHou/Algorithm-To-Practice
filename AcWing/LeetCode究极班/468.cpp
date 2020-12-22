
class Solution {
public:
    vector<string> split(string ip, char t) {
        vector<string> res;
        for (int i = 0; i < ip.size(); i ++ ) {
            int j = i;
            string item;
            while (ip[j] != t) item += ip[j ++ ];
            i = j;
            res.emplace_back(item);
        }
        return res;
    }

    string no = "Neither";
    string y4 = "IPv4";
    string y6 = "IPv6";

    string check_ipv4(string& ip) {
        auto items = split(ip + '.', '.');
        if (items.size() != 4) return no;
        for (auto& item: items) {
            if (item.empty() || item.size() > 3) return no;
            if (item.size() > 1 && item[0] == '0') return no;
            for (auto c: item)
                if (c < '0' || c > '9') return no;
            int t = stoi(item);
            if (t > 255) return no;
        }
        return y4;
    }

    string check_ipv6(string& ip) {
        auto items = split(ip + ':', ':');
        if (items.size() != 8) return no;
        for (auto& item: items) {
            if (item.empty() || item.size() > 4) return no;
            for (auto c: item) {
                if (!check(c)) return no;
            }
        }
        return y6;
    }

    inline bool check(char c) {
        if (isdigit(c)) return true;
        if (c >= 'a' && c <= 'f') return true;
        if (c >= 'A' && c <= 'F') return true;
        return false;
    }

    string validIPAddress(string ip) {
        if (ip.find('.') != string::npos)
            return check_ipv4(ip);
        return check_ipv6(ip);
    }
};