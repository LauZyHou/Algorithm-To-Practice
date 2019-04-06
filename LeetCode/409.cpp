#define reg register

class Solution {
public:
    int longestPalindrome(string s) {
		int ans=0;//一堆取偶数带一个奇数,或者全是偶数
		int oddNum=0;//记录奇数数量
		map<char,int> mp;
		for(reg auto c:s){
			mp[c]++;
		}
		for(reg auto m:mp){
			ans += m.second;
			oddNum += m.second & 1;
		}
		return (ans -= oddNum>=1?(oddNum-1):0);
    }
};