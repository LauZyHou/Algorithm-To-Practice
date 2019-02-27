class Solution {
public:
    /**
     * @param A: an integer array
     * @return: nothing
     */
	void swap(int &a,int &b){
		int c = a;
		a = b;
		b = c;
	}
	void quickSort(vector<int> &A,int x,int y){
		if(x>=y)
			return; 
		int base = A[x];
		int i=x;
		int j=y;
		while(i!=j){
			while(A[j]>=base && i<j) j--;
			while(A[i]<=base && i<j) i++;
			if(i<j)
				swap(A[i],A[j]);
		}
		A[x] = A[i];
		A[i] = base;
		quickSort(A,x,i-1);
		quickSort(A,i+1,y);
	}

    void sortIntegers(vector<int> &A) {
        quickSort(A,0,A.size()-1);
    }
};