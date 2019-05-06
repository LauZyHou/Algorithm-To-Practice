// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
		long long lft = 1;
		long long rgt = n;
		long long mid;
		int r;
		while((r=guess((mid=(lft+rgt)/2)))!=0){
			if(r<0)
				rgt = mid-1;
			else
				lft = mid+1;
		}
		return mid;
    }
};