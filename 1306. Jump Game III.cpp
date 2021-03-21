class Solution
{
public:
    bool fun(vector<int> &arr, vector<bool> &checked, int start, int &n)
    {
        checked[start] = true;
        int right = start + arr[start], left = start - arr[start];
        if (right < n)
        {
            if (arr[right] == 0)
            {
                return true;
            }
            if (!checked[right] && fun(arr, checked, right, n))
            {
                return true;
            }
        }
        if (left >= 0)
        {
            if (arr[left] == 0)
            {
                return true;
            }
            if (!checked[left] && fun(arr, checked, left, n))
            {
                return true;
            }
        }
        return false;
    }
    bool canReach(vector<int> &arr, int start)
    {
        vector<bool> checked(arr.size(), false);
        int n = arr.size();
        return fun(arr, checked, start, n);
    }
};