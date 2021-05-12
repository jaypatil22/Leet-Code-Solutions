class Solution
{
public:
    int trap(vector<int> &height)
    {
        if (height.size() == 0)
            return 0;
        int left = 0, right = height.size() - 1, res = 0;
        int ml = height[0];
        int mr = height[right];
        while (left < right)
        {
            if (height[left] < height[right])
            {
                ml = max(ml, height[left]);
                res += ml - height[left];
                left++;
            }
            else
            {
                mr = max(mr, height[right]);
                res += mr - height[right];
                right--;
            }
        }
        return res;
    }
};