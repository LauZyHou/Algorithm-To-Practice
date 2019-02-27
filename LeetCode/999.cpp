class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int x,y;
		for(x=0;x<8;x++)
			for(y=0;y<8;y++)
				if(board[x][y]=='R')
					goto ok;
		ok:
		int cnt=0;
		//top
		for(int j=y;j>=0;j--){
			if(board[x][j]=='B')
				break;
			else if(board[x][j]=='p'){
				cnt++;
				break;
			}
		}
		//down
		for(int j=y;j<8;j++){
			if(board[x][j]=='B')
				break;
			else if(board[x][j]=='p'){
				cnt++;
				break;
			}
		}
		//left
		for(int i=x;i>=0;i--){
			if(board[i][y]=='B')
				break;
			else if(board[i][y]=='p'){
				cnt++;
				break;
			}
		}
		//right
		for(int i=x;i<8;i++){
			if(board[i][y]=='B')
				break;
			else if(board[i][y]=='p'){
				cnt++;
				break;
			}
		}
		return cnt;
    }
};