class Solution
{
public:
    int minOperations(int n)
    {
        int m = n / 2;
        if (n % 2)
        {
            return m * (m + 1);
        }
        else
        {
            return m * m;
        }
    }
};