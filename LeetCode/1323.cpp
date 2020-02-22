class Solution {
public:
    int maximum69Number (int num) {
        bool fan = false;
        string s = to_string(num);
        int ans = 0;
        for(char c:s) {
            int v = c-'0';
            if(!fan && c=='6') {
                v = 9;
                fan = true;
            }
            ans = ans*10 + v;
        }
        return ans;
    }
};