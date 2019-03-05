class Solution {
public:
    bool hasAlternatingBits(int n) {
		int bits = 0;
		int fn = n;
		while(fn){
			fn>>=1;
			bits++;
		}
        int a = n^(n>>1);
		while(bits--){
			if(!(a&1))
				return false;
			a>>=1;
		}
		return true;
	}
};