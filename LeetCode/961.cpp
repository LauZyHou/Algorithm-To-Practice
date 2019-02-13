#include <bits/stdc++.h>
using namespace std;

class Solution
{
  private:
    int len;

  public:
    bool hasN(const vector<int> &A, int k)
    {
        int cnt=0;
        for(int i=0;i<len;i++){
            if(A[i]==k)
                cnt++;
            if(cnt==len/2)
                return true;
        }
        return false;
    }
    int repeatedNTimes(vector<int> &A)
    {
        len = A.size();
        int who = A[0], times = 1;
        for (int i = 1; i < len; i++)
        {
            if (A[i] == who)
            {
                times += 1;
            }
            else
            {
                times -= 1;
                if (times < 0)
                {
                    who = A[i];
                    times = 1;
                }
            }
        }
        if (times == 0)
        {
            if (this->hasN(A, A[len - 1]))
                return A[len - 1];
            return who;
        }
        return who;
    }
};

int main()
{
    Solution *s = new Solution();
    int a[] = {1,2,0,2,2,2,4,8};
    vector<int> v(a, a + 8);
    int result = s->repeatedNTimes(v);
    cout << result << endl;
    return 0;
}