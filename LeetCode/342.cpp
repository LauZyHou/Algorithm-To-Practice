class Solution {
public:
    bool isPowerOfFour(int num) {
        bool find=false;
		if(!num)
			return false;
		while(num && !find){
			if(num&1){
				if(find)
					return false;
				else
					find=true;
			}
			num>>=1;
			if(num&1)
				return false;
			num>>=1;
		}
		if(num)
			return false;
		return true;
    }
};