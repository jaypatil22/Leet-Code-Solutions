class Solution
{
public:
    string convertToTitle(int n)
    {
        string res = "";
        string alpha = "ZABCDEFGHIJKLMNOPQRSTUVWXY";
        while (n > 0)
        {
            int mod = n % 26;
            res = alpha[mod] + res;
            n /= 26;
            if (mod == 0)
            {
                n -= 1;
            }
        }
        return res;
    }
};