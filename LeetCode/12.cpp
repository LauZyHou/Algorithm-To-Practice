class Solution {
public:
    string intToRoman(int num) {
        string ss[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
		int is[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
		int idx = 0;
		string ans = "";
		while(idx<13) {
			while(num>=is[idx]) {
				num -= is[idx];
				ans += ss[idx];
			}
			idx++;
		}
		return ans;
    }
};