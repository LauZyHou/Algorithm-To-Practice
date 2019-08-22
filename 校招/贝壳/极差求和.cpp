//https://www.nowcoder.com/discuss/95743
//需要注意,计算最大/最小时候,左边和右边只有一边带等号,这样重复元素AB就不会重复计算
//也就是说从A找到B,那么就从B不会找回A
//或者从B找到A,那么从A不会找到B

#include<bits/stdc++.h>
using namespace std;

void myprint(vector<long long>& v) {
	int len = v.size();
	for(int i=0;i<len;i++)
		cout<<v[i]<<" ";
	cout<<endl;
}

void myprint(vector<int>& v) {
	int len = v.size();
	for(int i=0;i<len;i++)
		cout<<v[i]<<" ";
	cout<<endl;
}

int main() {
	int n;
	cin >> n;
	if (n <= 1) {
		cout << 0;
		return 0;
	}
	vector<long long> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	myprint(a);//3 2 2 2 1 4

	stack<pair<int, int> > s;//这种地方要带个空格,不能写成>>
	vector<int> c(n), d(n);
	//生成c序列,c[i]表示在a[i]左边且<=a[i]的最近元素a[j]的下标j
	for (int i = 0; i < n; i++) {
		while (!s.empty() && s.top().first > a[i])
			s.pop();
		if (s.empty())
			c[i] = -1;
		else
			c[i] = s.top().second;
		s.push({ a[i], i });//插入pair
	}
	
	myprint(c);//-1 -1 1 2 -1 4

	s = stack<pair<int, int> >();//清空栈
	//生成d序列,d[i]表示在a[i]右边且<a[i]的最近元素a[k]的下标k
	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() && s.top().first >= a[i])
			s.pop();
		if (s.empty())
			d[i] = n;
		else
			d[i] = s.top().second;
		s.push({ a[i], i });
	}

	myprint(d);//1 4 4 4 6 6

	long long res = 0;
	for (int i = 0; i < n; i++) {
		//有(i - c[i]) * (d[i] - i)这么多个包含a[i]的区间里a[i]是最小的,将其减去
		res -= a[i] * (i - c[i]) * (d[i] - i);
	}

	s = stack<pair<int, int> >();
	//生成c序列,c[i]表示在a[i]左边且>a[i]的最近元素a[j]的下标j
	for (int i = 0; i < n; i++) {
		while (!s.empty() && s.top().first <= a[i])
			s.pop();
		if (s.empty())
			c[i] = -1;
		else
			c[i] = s.top().second;
		s.push({ a[i], i });
	}
	
	myprint(c);//-1 0 0 0 3 -1

	s = stack<pair<int, int> >();
	//生成d序列,d[i]表示在a[i]右边且>=a[i]的最近元素a[k]的下标k
	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() && s.top().first < a[i])
			s.pop();
		if (s.empty())
			d[i] = n;
		else
			d[i] = s.top().second;
		s.push({ a[i], i });
	}
	
	myprint(d);//5 2 3 5 5 6

	for (int i = 0; i < n; i++) {
		//有(i - c[i]) * (d[i] - i)这么多个包含a[i]的区间里a[i]是最大的,将其加上
		res += a[i] * (i - c[i]) * (d[i] - i);
	}

	cout << res;
	return 0;

}
