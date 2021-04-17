class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        if (nums.size() <= 1 || k == 0)
            return false;
        unordered_map<int, int> s;
        for (int i = 0; i < nums.size() && i <= k; i++)
        {
            s[nums[i]]++;
            if (s[nums[i]] > 1)
                return true;
        }
        int l = 0, r = k + 1;
        while (r < nums.size())
        {
            s[nums[l]]--;
            l++;
            s[nums[r]]++;
            if (s[nums[r]]++ > 1)
                return true;
            r++;
        }
        return false;
    }
};