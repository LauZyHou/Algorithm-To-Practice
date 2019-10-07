class Solution
{
public:
    int maxNumberOfBalloons(string s)
    {
        int ch[26] = {0};
        for (char c : s)
        {
            ch[c - 'a']++;
        }
        int ans[] = {ch['b' - 'a'], ch['a' - 'a'], ch['l' - 'a'] / 2, ch['o' - 'a'] / 2, ch['n' - 'a']};
        int answer = ans[0];
        for (int i = 1; i <= 4; i++)
            answer = min(ans[i], answer);
        return answer;
    }
};