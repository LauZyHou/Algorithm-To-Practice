class Solution {
public:
	long long C(int a,int b){
		set<int> zi;
		for(int i=2;i<=b;i++)
			zi.insert(i);
		long long ans = 1;
		while(b--){
			ans*=a;
			a--;
			//遍历set,将ans及时除小,并移除已经除掉的元素
			set<int>::iterator it;
			for(it=zi.begin();it!=zi.end();it++)
				if(ans%(*it)==0){
					ans/=(*it);
					zi.erase(it);
				}
		}
		return ans;
	}

    vector<int> getRow(int n) {
		n++;//仅一个1视为第0行
        //杨辉三角的数学性质：第n行的m个数可表示为 C(n-1，m-1)
		//即为从n-1个不同元素中取m-1个元素的组合数（n,m从1开始计数）
		int i=0;
		vector<int> ans;
		for(;i<=n/2;i++)
			ans.push_back(C(n-1,i));
		for(;i<n;i++)
			ans.push_back(ans[n-1-i]);
		return ans;
    }
};