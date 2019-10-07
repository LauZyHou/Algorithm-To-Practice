class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        int ch[26] = {0};
        int ch2[26] = {0};
        for (char c : chars)
        {
            ch[c - 'a']++;
            ch2[c - 'a']++;
        }
        int ans = 0;
        for (string &s : words)
        {
            ans += s.size();
            for (char ss : s)
            {
                ch2[ss - 'a']--;
                if (ch2[ss - 'a'] < 0)
                {
                    ans -= s.size();
                    break;
                }
            }
            for (int i = 0; i < 26; i++)
            {
                ch2[i] = ch[i];
            }
        }
        return ans;
    }
};