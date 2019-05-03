class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
		int k = 31;
		while(k--){
			if(n&1)
				ans+=1;
			ans<<=1;
			n>>=1;
		}
		if(n&1)
			ans+=1;
		return ans;
    }
};