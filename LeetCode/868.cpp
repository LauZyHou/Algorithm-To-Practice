class Solution {
public:
    int binaryGap(int N) {
        int cnt = 0;
		int maxi = 0;
		while(N){
			if((N&1)==1)
				break;
			N>>=1;
		}
		N>>=1;
		while(N){
			cnt++;
			if((N&1)==1){
				if(cnt>maxi)
					maxi = cnt;
				cnt = 0;
			}
			N>>=1;
		}
		return maxi;
    }
};