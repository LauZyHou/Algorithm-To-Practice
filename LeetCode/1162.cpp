#include "./localtest/reader.cpp"

class Solution {
public:
    int maxDistance(vector<vector<int>>& vv) {
        int m = vv.size();
        int n = vv[0].size();
        int s = 0;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(vv[i][j]) {
                    q.push(make_pair(i,j));
                    s++;
                }
            }
        }
        if(s==0 || s==m*n)
            return -1;
        int rs[] = {0,1,0,-1};
        int cs[] = {-1,0,1,0};
        int ans = -1;
        while(!q.empty()) {
            ans++; // 每次扩一层
            int len = q.size();
            for(int i=0;i<len;i++) {
                pair<int,int> p = q.front(); // 这里用引用的话传上去会报错
                q.pop();
                int a = p.first;
                int b = p.second;
                for(int j=0;j<4;j++) {
                    int _a = a + rs[j];
                    int _b = b + cs[j];
                    if(_a<0 || _a>=m || _b<0 || _b>=n || vv[_a][_b]) {
                        continue;
                    }
                    vv[_a][_b] = 1;
                    q.push(make_pair(_a,_b));
                }
            }
        }
        return ans;
    }
};


int main() {
    Solution s;
    vector<vector<int>> vv = read_vv("localtest/testcase");
    for(int i=0;i<vv.size();i++) {
        for(int j=0;j<vv[i].size();j++) {
            cout << vv[i][j] << "\t";
        }
        cout << endl;
    }
    cout << s.maxDistance(vv) << endl;
    return 0;
}