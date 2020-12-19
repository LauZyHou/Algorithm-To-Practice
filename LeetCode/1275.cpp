class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>> g(3, vector<char>(3, 0));
        char s[2] = {'A', 'B'};
        for (int i = 0; i < moves.size(); i ++ ) {
            g[moves[i][0]][moves[i][1]] = s[i & 1];
        }
        for (int i = 0; i < 3; i ++ ) {
            if (g[i][0] && g[i][0] == g[i][1] && g[i][1] == g[i][2]) return string(1, g[i][0]);
            if (g[0][i] && g[0][i] == g[1][i] && g[1][i] == g[2][i]) return string(1, g[0][i]);
        }
        if (g[0][0] && g[0][0] == g[1][1] && g[1][1] == g[2][2]) return string(1, g[1][1]);
        if (g[0][2] && g[0][2] == g[1][1] && g[1][1] == g[2][0]) return string(1, g[1][1]);
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};