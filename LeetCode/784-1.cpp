//非递归版本
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
		int slen = S.size();
		string tmp = "";
		queue<string> q;
		q.push(tmp);
		for(int i=0;i<slen;i++){
			int qlen = q.size();
			while(qlen--){
				tmp = q.front();
				q.pop();
				//char转string
				stringstream stream;
				stream<<S[i];
				string ok = stream.str();
				//拼起来
				q.push(tmp+ok);
				if(S[i]<='z' && S[i]>='a' || S[i]<='Z' && S[i]>='A'){
					//char转string
					stringstream stream;
					stream<<(char)(S[i]^32);
					string ok = stream.str();
					//拼起来
					q.push(tmp+ok);
				}
			}
		}
		vector<string> ans;
		int qlen = q.size();
		while(qlen--){
			tmp = q.front();
			q.pop();
			ans.push_back(tmp);
		}
		return ans;
    }
};