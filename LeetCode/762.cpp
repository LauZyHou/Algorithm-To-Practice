class Solution {
private:
	set<int> primeSet;
	int prime[8] = {2,3,5,7,11,13,17,19};//2**20>10**6
public:
	Solution(){
		for(int i=0;i<8;i++)
			primeSet.insert(prime[i]);
	}

	int findBit1(int n){
		int res = 0;
		while(n){
			if((n&1)==1)
				res++;
			n>>=1;
		}
		return res;
	}

	bool isPrime(int r){
		return this->primeSet.count(r);
	}

    int countPrimeSetBits(int L, int R) {
        int ans = 0;
		for(int i=L;i<=R;i++){
			if(isPrime(findBit1(i)))
				ans++;
		}
		return ans;
    }
};