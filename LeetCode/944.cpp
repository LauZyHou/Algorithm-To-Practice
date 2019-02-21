class Solution {
	private:
		int ans=0;

	public:
		int minDeletionSize(vector<string>& A) {
			int colNum = A[0].length();
			for(int j=0; j<colNum; j++) {
				char c = A[0][j];
				for(int i=1; i<A.size(); i++) {
					if(A[i][j]<c) {
						ans++;
						break;
					}
					c = A[i][j];
				}
			}
			return ans;
		}
};
