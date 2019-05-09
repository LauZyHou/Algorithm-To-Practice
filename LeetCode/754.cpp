class Solution {
public:
    int reachNumber(int t) {
		t = abs(t);
		int n = 1;
		int sum = 0;
		while(true) {
			sum += n;
			if(sum<t)
				n++;
			else
				break;
		}
		if(sum==t || (sum-t)%2==0)
			return n;
		if((sum+n+1-t)%2==0)
			return n+1;
		return n+2;
    }
};