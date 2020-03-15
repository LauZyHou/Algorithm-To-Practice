class Solution {
private:
    static const int mod = 1e9 + 7;
    // 按efficiency从大到小排序
    static bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
        // if(a.second==b.second)
        //     return a.first < b.first;
        // 效率一样时，不用考虑速度的顺序，随便什么顺序放，插入堆时再检查就行了
        return a.second > b.second;
    }
public:
    int maxPerformance(int n, vector<int>& sp, vector<int>& ef, int k) {
        vector<pair<int,int>> vp(n);
        for(int i=0;i<n;i++) {
            vp[i] = make_pair(sp[i], ef[i]);
        }

        sort(vp.begin(), vp.end(), cmp);

        long long ans = INT_MIN;

        // 升序队列即最小堆，里面放的是速度
        priority_queue<int,vector<int>,greater<int> > q;
        // 记录到当前为止堆中几个工程师的速度和
        long long sum = 0;

        // 正序遍历时，每次遇到的都是当前遇到过"效率最低"的一个，尝试将其作为最低效的
        for(int i=0;i<n;i++) {
            int nowEf = vp[i].second;
            int nowSp = vp[i].first;
            // 堆满了，要和堆顶检查一下，当前的会不会速度更大
            // 如果是速度相等没必要换，因为当前的效率不会更高
            if(k==q.size() && q.top()<nowSp) {
                sum -= q.top();
                q.pop();
                q.push(nowSp);
                sum += nowSp;
            }
            // 堆没满直接插入
            else if (k>q.size()) {
                q.push(nowSp);
                sum += nowSp;
            }
            else {
                continue;
            }
            if (sum*nowEf > ans)
                ans = sum*nowEf;
        }
        return ans % mod;
    }
};