class Solution
{
public:
    int minCostToMoveChips(vector<int> &v)
    {
        int odd = 0;
        int even = 0;
        for (int vv : v)
        {
            if ((vv & 1) == 1)
                odd++;
            else
                even++;
        }
        return min(odd, even);
    }
};