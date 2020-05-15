#include<bits/stdc++.h>
using namespace std;


class Solution {
private:
    // 翻转
    string rev(string s, int a, int b) {
        while(a < b) {
            swap(s[a], s[b]);
            a++;
            b--;
        }
        return s;
    }

    // 去除两端空格
    string trip(string s) {
        int len = s.size();
        int left = 0;
        int right = len-1;
        while(left < len && s[left]==' ')
            left++;
        while(right >=0 && s[right]==' ')
            right--;
        if(right < left)
            return "";
        return s.substr(left, right-left+1);
    }

    // 去除中间多余空格
    string rm(string s) {
        bool space = false;
        int len = s.size();
        int j = 0;
        char* ch = new char[len+1];
        for(int i=0;i<len;i++) {
            if(s[i]==' ') {
                if(!space) {
                    ch[j++] = s[i];
                }
                space = true;
            }
            else {
                ch[j++] = s[i];
                space = false;
            }
        }
        ch[j] = '\0';
        return string(ch);
    }

public:
    string reverseWords(string s) {
        int len = s.size();
        if(!len)
            return s;
        s = rev(s, 0, len-1);
        int a = -1; // begin
        for(int i=0 ; i<len ; i++) {
            if(s[i]==' ') {
                if(a >= 0) {
                    s = rev(s, a, i-1);
                    a = -1;     
                } 
            }
            else {
                if(a < 0) {
                    a = i;
                }
            }
        }
        if (a >= 0) {
            s = rev(s, a, len-1);
        }
        return rm(trip(s));
    }
};


int main() {
    Solution s;
    string m = s.reverseWords(" ");
    cout << "(" <<  m  << ")" << endl;
    return 0;
}
