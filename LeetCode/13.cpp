class Solution {
private:
	map<char,int> mp;
public:
	Solution(){
		mp['I'] = 1;
		mp['V'] = 5;
		mp['X'] = 10;
		mp['L'] = 50;
		mp['C'] = 100;
		mp['D'] = 500;
		mp['M'] = 1000;
	}

    int romanToInt(string s) {
		int len = s.size();
		int ans = 0;
		for(int i=0;i<len-1;i++){
			if(mp[s[i]]<mp[s[i+1]])
				ans-=mp[s[i]];
			else
				ans+=mp[s[i]];
		}
		return ans+mp[s[len-1]];
    }
};