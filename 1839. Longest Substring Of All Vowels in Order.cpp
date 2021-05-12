class Solution
{
public:
    int longestBeautifulSubstring(string word)
    {
        int ma = 0, len = 1, cnt = 1;
        for (int i = 1; i < word.size(); i++)
        {
            if (word[i] == word[i - 1])
            {
                len++;
            }
            else if (word[i] > word[i - 1])
            {
                len++;
                cnt++;
            }
            else
            {
                len = 1;
                cnt = 1;
            }
            if (cnt == 5)
            {
                ma = max(ma, len);
            }
        }
        return ma;
    }
};