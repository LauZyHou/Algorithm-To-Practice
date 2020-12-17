class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string> hash;
        hash.insert("0,0");
        int x = 0, y = 0;
        for (auto c: path) {
            switch (c) {
                case 'N':
                    x ++ ;
                    break;
                case 'E':
                    y ++ ;
                    break;
                case 'S':
                    x -- ;
                    break;
                case 'W':
                    y -- ;
                    break;
            }
            string s = to_string(x) + ',' + to_string(y);
            if (hash.count(s)) return true;
            hash.insert(s);
        }
        return false;
    }
};