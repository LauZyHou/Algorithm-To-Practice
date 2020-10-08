class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target = "123450";
        string start = "";
        for (int i = 0; i < 2; i ++)
            for (int j = 0; j < 3; j ++)
                start.push_back(board[i][j] + '0');
        vector<vector<int> > nei = {
            {1, 3},
            {0, 4, 2},
            {1, 5},
            {0, 4},
            {3, 1, 5},
            {2, 4}
        };

        queue<string> q;
        unordered_set<string> visited;
        q.push(start);
        visited.insert(start);

        int lev = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i ++) {
                string cur = q.front();
                q.pop();
                if (cur == target)
                    return lev;
                int idx = 0;
                for ( ; cur[idx]!='0'; idx ++)
                    ;
                for (int adj : nei[idx]) {
                    string newstate = cur;
                    swap(newstate[adj], newstate[idx]);
                    if (!visited.count(newstate)) {
                        q.push(newstate);
                        visited.insert(newstate);
                    }
                }
            }
            lev ++;
        }
        return -1;
    }
};