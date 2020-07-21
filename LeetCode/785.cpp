enum Color {
    R, G, N
};

class Solution {
public:
    bool isBipartite(vector<vector<int>>& g) {
        int glen = g.size();
        vector<Color> v(glen, N);
        for(int i=0;i<glen;i++) {
            if(v[i]!=N)
                continue;
            queue<int> q;
            q.push(i);
            v[i] = R;
            while(q.empty()==false) {
                int node = q.front();
                q.pop();
                Color other = v[node]==R ? G : R;
                for(int nei:g[node]) {
                    if(v[nei]==N) {
                        v[nei] = other;
                        q.push(nei);
                    }
                    else if(v[nei]!=other) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};