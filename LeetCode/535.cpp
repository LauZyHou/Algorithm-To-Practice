#include<bits/stdc++.h>
using namespace std;

class Solution {
	private:
		map<string,string> longToShort;
		map<string,string> shortToLong;
		set<string> s;//short
		string base = "http://tinyurl.com/";

	public:

		// Encodes a URL to a shortened URL.
		string encode(string longUrl) {
			//没存过
			if(longToShort.find(longUrl)==longToShort.end()) {
				//随机生成字符串pstr,保证无重复
				char p[100]="";
				string pstr="";
				do {
					int len = rand()%15+1;//1~15
					p[len]='\0';
					for(int i=0; i<len; i++) {
						int ascii;
						int upper=rand()%2;//是否大写
						if(upper) {
							ascii=rand()%('Z'-'A'+1)+'A';
						} else {
							ascii=rand()%('z'-'a'+1)+'a';
						}
						p[i]=(char)ascii;
					}
					pstr=p;
				} while(s.count(pstr));
				//记录
				s.insert(pstr);
				longToShort[longUrl]=pstr;
				shortToLong[pstr]=longUrl;
			}
			return base + longToShort[longUrl];
		}

		// Decodes a shortened URL to its original URL.
		string decode(string shortUrl) {
			shortUrl=shortUrl.replace(0,base.size(),"");
			return shortToLong[shortUrl];
		}
};


int main() {
	Solution s;
	string ok("123");
	string okk("234");
//	cout<<111<<endl;
	string ok2=s.encode(ok);
	cout<<ok2<<endl;
	cout<<s.decode(ok2)<<endl;
//	cout<<s.encode(okk)<<endl;
	return 0;
}
