#include<bits/stdc++.h>
using namespace std;

int l,r,k;
#define ll long long

ll sum(ll n) {
	//k^0 ~ k^1-1 可1次消除
	//k^1 ~ k^2-1 可1+k次消除
	//k^2 ~ k^3-1 可1+k+k^2次消除
	ll kf = 1;//初始,k的0次方为1
	ll ret = 0;//总消除次数
	ll p = 1;//当前这些数字所需消除次数
	while(kf*k-1<n) {
		ret += p*(kf*k-1 - kf + 1)%2;//反正最后是求差的奇偶,这里模2不影响
		p += k;
		kf = kf*k;
	}
	//最后剩下的那些
	ret += p*(n - kf + 1);
	return ret;
}

int main() {
	while(scanf("%d%d%d",&l,&r,&k)!=EOF) {
		//仅当k=1时会无限循环导致平手
		if(k==1)
			puts("Draw");
		else if(((sum(r)-sum(l-1))&1)==1)//奇数
			puts("XHRlyb");
		else
			puts("Cwbc");
	}
	return 0;
}
