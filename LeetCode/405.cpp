class Solution {
public:
    string toHex(int num) {
		if(!num)
			return "0";
		string hex = "0123456789abcdef";
		string ans = "";
		int cnt = 0;
		while(num && cnt<8){
			ans = hex[num & 0xf] + ans;
			num>>=4;
			cnt++;
		}
		return ans;
    }
};