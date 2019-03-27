class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: if string A contains all of the characters in B return true else return false
     */
    bool compareStrings(string &A, string &B) {
        int a[26]={0};
		int b[26]={0};
		int alen = A.size();
		int blen = B.size();
		for(int i=0;i<alen;i++)
			a[A[i]-'A']++;
		for(int i=0;i<blen;i++)
			b[B[i]-'A']++;
		for(int i=0;i<26;i++)
			if(a[i]<b[i])
				return false;
		return true;
    }
};