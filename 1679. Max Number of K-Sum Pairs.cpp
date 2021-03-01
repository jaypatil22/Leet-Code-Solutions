class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        multiset<int> set;
        for (int a : nums)
        {
            set.insert(a);
        }
        int res = 0;
        for (int a : nums)
        {
            if (a < k && set.find(a) != set.end())
            {
                set.erase(set.find(a));
                if (set.find(k - a) != set.end())
                {
                    res++;
                    set.erase(set.find(k - a));
                }
                else
                {
                    set.insert(a);
                }
            }
        }
        return res;
    }
};