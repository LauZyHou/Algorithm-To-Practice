class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int len = S.size();
		vector<int> ans(len);
		vector<int> idx(len);//size<len
		int lenIdx = 0;
		//find all index which is C
		for(int i=0;i<len;i++)
			if(S[i]==C)
				idx[lenIdx++]=i;
		//gen ans
		int j=0;//for ans
		for(int i=0;i<lenIdx;i++){
			//begin
			if(i==0){
				while(j<idx[0])
					ans[j++]=idx[0]-j;
			}
			//between two C
			else{
				int mid = (idx[i]+idx[i-1])/2;
				while(j<=mid)
					ans[j++]=j-idx[i-1];
				while(j<idx[i])
					ans[j++]=idx[i]-j;
			}
			ans[j]=0;
		}
		//end
		while(j<len)
			ans[j++]=j-idx[lenIdx-1];
		return ans;		
    }
};