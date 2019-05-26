class Solution {
public:
	set<int>* p_st_ar = nullptr;
	bool* fv_ar = nullptr;
	int* ans;

	Solution() {
		ans = new int[10010];
	}

	//上色
	void go(int k) {
		if(fv_ar[k])
			return ;
		//cout<<k<<"->";
		bool color_ok[4] = {true,true,true,true};
		set<int>::iterator it = p_st_ar[k].begin();
		while(it!=p_st_ar[k].end()) {
			if(true==fv_ar[*it])
				color_ok[ans[*it]-1] = false;
			//cout<<*it<<" ";
			it++;
		}
		for(int i=0;i<4;i++)
			if(color_ok[i]) {
				ans[k] = i+1;
				break;
		}
		fv_ar[k] = true;
		//cout<<endl;
	}
	
	vector<int> gardenNoAdj(int n, vector<vector<int>>& p_v) {
		p_st_ar = new set<int>[n];
		for(int i=0;i<n;i++)
			p_st_ar[i] = set<int>();
		int vlen = p_v.size();
		for(int i=0;i<vlen;i++) {
			int a = p_v[i][0] - 1;
			int b = p_v[i][1] - 1;
			p_st_ar[a].insert(b);
			p_st_ar[b].insert(a);
		}
		fv_ar = new bool[n];
		for(int i=0;i<n;i++) {
			fv_ar[i] = false;
		}
		for(int i=0;i<n;i++)
			go(i);
		//relese heap
		delete[] p_st_ar;
		delete[] fv_ar;
		return vector<int>(ans,ans+n);
    }
};