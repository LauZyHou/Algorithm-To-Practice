class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int len = arr.size();
		int zeros = 0;
		for(int i=0;i<len;i++)
			if(arr[i]==0)
				zeros++;
		int nlen = len + zeros;
		for(int i=len-1,j=nlen-1;i>=0 && j>=0;i--) {
			if(arr[i]==0) {
				if(j<len)
					arr[j--] = 0;
				else
					j--;
				if(j<len)
					arr[j--] = 0;
				else
					j--;
			}else {
				if(j<len)
					arr[j--] = arr[i];
				else
					j--;
			}
		}
    }
};