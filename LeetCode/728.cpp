class Solution {
public:
	bool isZiChu(int n){
		if(n<10)
			return true;
		int r=n;
		while(n){
			int k=n%10;
			if(k==0 || r%k!=0)
				return false;
			n/=10;
		}
		return true;
	}

	vector<int> selfDividingNumbers(int left, int right) {
		vector<int> v;
        	for(int i=left;i<=right;i++)
			if(isZiChu(i))
				v.push_back(i);
		return v;
	}
};




