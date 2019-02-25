bool cmp(vector<int> a,vector<int> b){
    // cout<<a[0]<<" "<<a[1]<<" "<<b[0]<<" "<<b[1]<<endl;
    return (a[0]*a[0]+a[1]*a[1])>(b[0]*b[0]+b[1]+b[1]);
}

class Solution {
public:
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
            /*
        for(int i=0;i<points.size();i++){
            cout<<points[i][0]<<" "<<points[i][1]<<endl;
        }*/
        vector<vector<int>> ans;
        std::sort(points.begin(),points.end(),cmp);
        for(int i=0;i<K;i++)
            ans.push_back(points[i]);
        return ans;
    }
};

