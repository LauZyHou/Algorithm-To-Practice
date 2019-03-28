class Solution {
public:
    int bitwiseComplement(int N) {
        //1010->0101即可以和1111进行异或得到
		//所以只要判断一下有多少位就可以了
		if(!N)
			return 1;
		int n = N;
		int ans = 0;
		while(n){
			n>>=1;
			ans = (ans<<1) +1;
		}
		return N^ans;
    }
};