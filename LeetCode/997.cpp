class Solution {
public:
    int findJudge(int N, vector<vector<int>>& t) {
        //题目中保证了trust[i]是完全不同的,所以只要记录数量
		int len = t.size();
		if(len<N-1)
			return -1;
		int a[1002]={0};
		//是否信任过别人,注意没法通过改这里为true让其全部初始化为true
		bool b[1002]={false};
		for(int i=0;i<len;i++){
			b[t[i][0]] = true;
			a[t[i][1]]++;
		}
		for(int j=1;j<=N;j++){
			if(!b[j] && a[j]==N-1)
				return j;
		}
		return -1;
    }
};