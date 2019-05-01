class Solution {
public:
	static bool cmp(vector<int> a,vector<int> b){
		return a[1]-a[0]>b[1]-b[0];
	}

    int twoCitySchedCost(vector<vector<int>>& costs) {
		int n = costs.size()/2;
		if(n==0)
			return 0;
        sort(costs.begin(),costs.end(),cmp);
		int ans = 0;
		for(int i=0;i<n;i++){
			ans += costs[i][0] + costs[i+n][1];
		}
		return ans;
    }
};