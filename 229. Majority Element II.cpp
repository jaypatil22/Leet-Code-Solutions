class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int a = 0, b = 1, count1 = 0, count2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == a)
            {
                count1++;
            }
            else if (nums[i] == b)
            {
                count2++;
            }
            else if (count1 == 0)
            {
                a = nums[i];
                count1 = 1;
            }
            else if (count2 == 0)
            {
                b = nums[i];
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == a)
                count1++;
            else if (nums[i] == b)
                count2++;
        }
        vector<int> res;
        if (count1 > ceil((nums.size() / 3)))
            res.emplace_back(a);
        if (count2 > ceil((nums.size() / 3)))
            res.emplace_back(b);
        return res;
    }
};