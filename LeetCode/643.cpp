class Solution {
public:
    double findMaxAverage(vector<int>& v, int k) {
        double sum = 0;
		int n = v.size();
		int i=0;
		for(;i<k;i++) {
			sum += v[i];
		}
		double maxsum = sum;
		for(;i<n;i++) {
			sum += v[i];
			sum -= v[i-k];
			if(sum > maxsum) 
				maxsum = sum;
		}
		return maxsum/k;
    }
};