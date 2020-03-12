class Solution {
public:
    string generateTheString(int n) {
        if(!n)
            return "";
        char* ans = new char[n+1];
        ans[n] = '\0';
        for(int i=0;i<n-1;i++)
            ans[i] = 'a';
        if(n&1)
            ans[n-1] = 'a';
        else
            ans[n-1] = 'b';
        return string(ans);
    }
};