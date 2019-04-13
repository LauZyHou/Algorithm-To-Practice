class Solution {
public:
    string reverseStr(string s, int k) {
        int len = s.size();
		int i = 0;
		while(i<len){
			int t=min(k,len-i);
			for(int j=0;j<t/2;j++){
				swap(s[i+j],s[i+(t-1-j)]);
			}
			i+=2*k;
		}
		return s;
    }
};