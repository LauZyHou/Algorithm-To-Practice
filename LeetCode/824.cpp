class Solution {
public:
	bool yuan(char c){
		return c=='a' || c=='e' || c=='i' || c=='o' || c=='u'
		|| c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
	}

    string toGoatLatin(string s) {
        string temp;
		stringstream ss(s);
		string ans = "";
		int cnt = 1;
		while(ss>>temp){
			if(yuan(temp[0]))//元音
				temp+="ma";
			else{//辅音
				if(temp.size()>1){//只有一个(辅音)字母时就不用往后提了
					string head=temp.substr(0,1);
					temp=temp.substr(1);
					temp+=head;
				}
				temp+="ma";
			}
			for(int j=0;j<cnt;j++)
				temp+="a";
			temp+=" ";//和下一个单词隔开
			ans+=temp;
			cnt++;
		}
		//删除最后一个空格
		ans.pop_back();
		return ans;
    }
};