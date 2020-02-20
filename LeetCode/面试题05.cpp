class Solution {
public:
    string replaceSpace(string s) {
        string ans = "";
        for(char c:s){
            if(c==' '){
                ans += "%20";
            }
            else {
                string r = "a";
                r[0] = c;
                ans += r;
            }
        }
        return ans;
    }
};