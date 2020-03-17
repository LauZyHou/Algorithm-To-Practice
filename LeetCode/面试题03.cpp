class Solution {
public:
    int findRepeatNumber(vector<int>& v) {
        int len = v.size();
        for(int i=0;i<len;i++) {
            // 把当前为止的v[i]换到index=v[i]的位置上去
            // 不断这样做，直到当前位置换出正确的数字i
            // 当发现换进去的和换出来的一样时，就说明有重复了直接返回
            while(i!=v[i]) {
                if(v[i]==v[v[i]])
                    return v[i];
                swap(v[i], v[v[i]]);
            }
        }
        return -1;
    }
};