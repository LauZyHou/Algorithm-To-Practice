class Solution {
public:
    bool isPowerOfTwo(int n) {
		bool find=false;
		if(!n)
			return false;
		while(n && !find){
			if(n&1)
				find=true;
			n>>=1;
		}
		return !n;
    }
};