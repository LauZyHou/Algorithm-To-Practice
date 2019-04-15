class Solution {
public:
    void merge(vector<int>& v1, int m, vector<int>& v2, int n) {
		int i = m+n-1;
		int r = m-1;
		while(r>=0){
			v1[i--] = v1[r--];
		}
		i++;
		r = 0;
		int j = 0;
		while(i<m+n && j<n){
			if(v1[i]<v2[j])
				v1[r++] = v1[i++];
			else
				v1[r++] = v2[j++];
		}
		while(i<m+n)
			v1[r++] = v1[i++];
		while(j<n)
			v1[r++] = v2[j++];
    }
};