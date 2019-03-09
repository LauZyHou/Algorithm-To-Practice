class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<map<char,int>> vm;
		int len = A.size();
		for(int i=0;i<len;i++){
			int slen = A[i].size();
			map<char,int> vmi;
			for(int j=0;j<slen;j++)
				if(vmi[A[i][j]])
					vmi[A[i][j]]+=1;
				else
					vmi[A[i][j]]=1;
			vm.push_back(vmi);
		}
		vector<string> ans;
		for(char c='a';c<='z';c++){
			int cNum = 0;
			for(int i=0;i<len;i++){
				if(vm[i][c]){
					if(cNum==0 || vm[i][c]<cNum)
						cNum = vm[i][c];
				}
				else{
					cNum = 0;
					break;
				}
			}
			for(int j=0;j<cNum;j++){
				char cs[2] = {c,'\0'};
				string s = cs;
				ans.push_back(s);
			}
		}
		return ans;
    }
};