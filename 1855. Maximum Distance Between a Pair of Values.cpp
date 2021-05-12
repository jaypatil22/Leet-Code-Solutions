class Solution
{
public:
    int find(vector<int> &a, int i, int k)
    {
        int l = i, h = a.size() - 1, res = -1;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (a[mid] < k)
            {
                h = mid - 1;
            }
            else
            {
                res = mid;
                l = mid + 1;
            }
        }
        return res;
    }
    int maxDistance(vector<int> &nums1, vector<int> &nums2)
    {
        int res = 0;
        for (int i = 0; i < nums1.size(); i++)
        {
            int j = find(nums2, i, nums1[i]);
            if (res != -1 && res < j - i)
            {
                res = j - i;
            }
        }
        return res;
    }
};