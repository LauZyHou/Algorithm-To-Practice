#include<bits/stdc++.h>
using namespace std;

char c[][5]= {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};


class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> s;//unique
        int sz=words.size();
        for(int i=0;i<sz;i++){
            string str="";
            int len=words[i].length();
            for(int j=0;j<len;j++){
                str+=c[words[i][j]-'a'];
            }
            s.insert(str);
        }
        return s.size();
    }
};
