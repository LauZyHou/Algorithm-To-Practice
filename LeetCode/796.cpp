class Solution {
private:
	char a[200];
	char f[100];
public:
    bool rotateString(string A, string B) {
		int alen = A.size();
		int blen = B.size();
		if(!alen && !blen)
			return true;
		if(alen!=blen)
			return false;
		for(int i=0;i<alen;i++){
			a[i] = a[i+alen] = A[i];
		}
		//get f
		f[0] = -1;
		for(int i=1;i<blen;i++){
			//get f[i]
			int j = f[i-1];
			while(B[i]!=B[j+1] && j>=0)
				j = f[j];
			if(B[i]==B[j+1])
				f[i] = j+1;
			else
				f[i] = -1;
		}
		//kmp
		int i = 0;
		int j = 0;
		while(i<2*alen){
			if(a[i]==B[j]){
				i++;
				j++;
				if(j==blen)
					return true;
			}else{
				if(j==0)
					i++;
				else
					j = f[j-1]+1;
			}
		}
		return false;
    }
};