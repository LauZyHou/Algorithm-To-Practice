class Solution {
public:
    string replaceSpaces(string s, int n) {
        int spaceNum = 0;
        for(int i=0;i<n;i++) {
            if(s[i]==' ')
                spaceNum++;
        }
        int newlen = n + spaceNum * 2;
        int q = newlen-1;
        int p = n-1;
        while(p>=0) {
            if(s[p]==' ') {
                s[q--] = '0';
                s[q--] = '2';
                s[q--] = '%';
            }
            else {
                s[q--] = s[p];
            }
            p--;
        }
        return s.substr(0, newlen);
    }
};