class Solution {
public:
	vector<int> v;
	int ans;
	int N;

	void backtrack(int t) {
		if(t>N) {
			ans++;
			return ;
		}
		for(int i=t;i<=N;i++) {
			if(v[i]%t==0 || t%v[i]==0) {
				swap(v[t],v[i]);
				backtrack(t+1);
				swap(v[t],v[i]);
			}
		}
	}

    int countArrangement(int N) {
		v = vector<int>(N+1);
		ans = 0 ;
		this->N = N;
		for(int i=1;i<=N;i++)
			v[i] = i;
		backtrack(1);
		return ans;
    }
};