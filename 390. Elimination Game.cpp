class Solution
{
public:
    int lastRemaining(int n)
    {
        bool r = 1;
        int start = 1;
        int end = n;
        int interval = 1;
        while (start != end)
        {
            if (r)
            {
                end = (end - start) % (interval * 2) == 0 ? end - interval : end;
                start += interval;
            }
            else
            {
                start = (end - start) % (interval * 2) == 0 ? start + interval : start;
                end -= interval;
            }
            interval *= 2;
            r = !r;
        }
        return start;
    }
};