class Solution
{
public:
    double myPow(double x, int n)
    {
        double res = 1;
        int sign = n < 0 ? -1 : 1;
        n = abs(n);
        while (n > 0)
        {
            if (n & 1)
            {
                res *= x;
            }
            x = x * x;
            n /= 2;
        }
        if (sign == -1)
        {
            res = 1 / res;
        }
        return res;
    }
};