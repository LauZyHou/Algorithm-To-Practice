#include<bits/stdc++.h>
using namespace std;

int m;
int t,n,k1,k2;
int cnt;
int r;
string k;
int klen;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&m,&n,&k1,&k2);
		if(!m){
			for(int i=k1;i<=k2;i++)
				printf("0");
			printf("\n");
			continue;
		}
		cnt = 1;
		if(m<0)
			m = -m;
		if(n<0)
			n = -n;
		while(cnt<=k2){
			m = (m%n)*1000;
			if(cnt>=k1 && cnt<=k2){
				r = m/n;
				k = to_string(r);
				klen = 0;
				int tmp = r;
				while(tmp){
					tmp/=10;
					klen++;
				}
				if(!klen) klen=1;
				if(cnt+klen>k2){
					for(int i=0;i<k2-cnt;i++)
						printf("%c",k[i]);
				}else
					printf("%d",r);
			}
			cnt+=klen;
		}
		printf("\n");
	}
	return 0;
}