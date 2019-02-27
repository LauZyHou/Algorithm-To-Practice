class Solution {
private:
	long long pow10[100]={0};
public:
    /**
     * @param k: An long longeger
     * @param n: An long longeger
     * @return: An long longeger denote the count of digit k in 1..n
     */
	long long numLen(long long r){
		long long len = 1;
		while(r/pow(10,len)){
			len++;
		}
		return len;
	}

	long long pow(long long a,long long b){
		if(!b)
			return 1;
		if(a==10 && !pow10[b])
			return pow10[b];

		long long base = 1;
		while(b--)
			base*=a;

		if(a==10)
			pow10[b]=base;

		return base;
	}

    long long digitCounts(long long k, long long n) {
		//n=12345 k=3
		//0*10000  len==5 start
		//1*1000   len==4
		//12*100+45+1  len==3
		//123*10+10   len==2
		//1234*1+1  len==1 end
		//--------------------------------
		//n=3020 k=0
		//(3-1)*100+20+1 len==4-1 start
		//30*10 len==2
		//(302-1)*1+0+1 len==1 end
        long long len = numLen(n);
		long long cnt = 0;
		if(k){
			while(len--){
				long long nowPosNum = n/pow(10,len-1)%10;
				if(nowPosNum>k){
					cnt = cnt + (n/pow(10,len)+1)*pow(10,n-1);
				}else if(nowPosNum==k){
					cnt = cnt +n/pow(10,len)*pow(10,n-1) + n%pow(10,len-1) + 1;
				}else{//<k
					cnt = cnt + n/pow(10,len-1)*pow(10,len-1);
				}
			}
		}else{//k==0
			while(--len){//最高位不能是0,所以len直接从len-1开始判断即可
				long long nowPosNum = n/pow(10,len-1)%10;
				if(nowPosNum==0){
					cnt = cnt + n/pow(10,len-1)*pow(10,len-1) + n%pow(10,len-1) + 1;
				}else{//>0
					cnt = cnt + n/pow(10,len)*pow(10,len-1);
				}
			}
		}
		return cnt;
    }
};