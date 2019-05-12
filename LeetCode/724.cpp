class Solution {
public:
    int pivotIndex(vector<int>& v) {
        int len = v.size();
		if(!len)
			return -1;
		int* a = new int[len];
		int* b = new int[len];
		a[0] = b[len-1] = 0;
		for(int i=1;i<len;i++)
			a[i] = a[i-1]+v[i-1];
		for(int i=len-2;i>=0;i--)
			b[i] = b[i+1]+v[i+1];
		for(int i=0;i<len;i++)
			if(a[i]==b[i])
				return i;
		return -1;
    }
};