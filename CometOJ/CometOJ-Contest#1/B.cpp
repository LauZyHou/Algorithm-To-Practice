#include<bits/stdc++.h>
using namespace std;

const int N = 1000000;

#define ll long long

bool lx0[N+2]={false};//为false时说明到现在为止都是连续0,非0开始后面全是true
char s[N+2];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",s+1);
		//得到lx0数组
		for(int i=1;s[i];i++){
			lx0[i] = lx0[i-1];//则后面不管是不是0都取到true
			if(s[i]!='0')//出现非0时记录
				lx0[i] = true;
		}
		ll ans = 0;//如果全是9,最大(1+2e5)*2e5/2大概2e10
		int lx9 = 0;//连续9的个数
		//从前往后dp,这里i表示所取子串的结束位置
		for(int i=1;s[i];i++){
			if(s[i]=='9')
				lx9+=1;
			else
				lx9=0;
			//0~8在+1之后都不可能有进位,所以结果都是一样
			if(s[i]<'9')
				ans+=1;
			//结尾是9,看看有几个连续9
			//'12999'=>'129910'/'129109'/'121099'/'13000'/'13000'
			//三个连续9三种样子,前面的都是同一种样子
			//如果前面是连续0呢?
			//'0..0999'=>'0..09910'/'0..09109'/'0..01099'就这三种
			//所以要看一下前面是不是连续0,不是连续0就加1,所以前面用true表示不连续0
			else
				ans += lx9 + (int)(lx0[i-lx9]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}