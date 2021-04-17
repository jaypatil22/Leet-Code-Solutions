class Solution
{
public:
    int arraySign(vector<int> &nums)
    {
        int neg = 0;
        for (int a : nums)
        {
            if (a < 0)
            {
                neg++;
            }
            else if (a == 0)
            {
                return 0;
            }
        }
        if (neg % 2)
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }
};