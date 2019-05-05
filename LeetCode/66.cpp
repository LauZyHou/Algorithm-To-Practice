class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        int len = d.size();
		int *a = new int[len+1];
		int i = len, j = len-1;
		d[j] += 1;
		int c = 0;
		while(j>=0) {
			a[i] = (d[j]+c)%10;
			c = (d[j]+c)/10;
			i--,j--;
		}
		if(c>0) {
			a[0] = c;
			return vector<int>(a, a+1+len);
		}
		return vector<int>(a+1, a+1+len);
    }
};