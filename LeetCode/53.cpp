class Solution {
public:
    int maxSubArray(vector<int>& v) {
		int len = v.size();
		if(!len)
			return 0;
		int ans = v[0];
		for(int i=1;i<len;i++){
			if(v[i-1]>0){
				v[i]+=v[i-1];
			}
			if(v[i]>ans)
				ans=v[i];
		}
		return ans;
    }
};