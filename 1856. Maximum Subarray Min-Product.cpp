class Solution
{
public:
    int maxSumMinProduct(vector<int> &nums)
    {
        vector<long long> presum(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
        {
            presum[i] += presum[i - 1];
        }
        vector<int> left(nums.size()), right(nums.size());
        stack<int> st;
        for (int i = 0; i < nums.size(); i++)
        {
            while (!st.empty() && nums[i] <= nums[st.top()])
            {
                st.pop();
            }
            if (!st.empty())
                left[i] = st.top() + 1;
            else
                left[i] = 0;
            st.push(i);
        }
        st = {};
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[i] <= nums[st.top()])
            {
                st.pop();
            }
            if (!st.empty())
                right[i] = st.top() - 1;
            else
                right[i] = nums.size() - 1;
            st.push(i);
        }
        long long res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            long long r = presum[right[i]], l = (left[i] == 0 ? 0 : presum[left[i] - 1]);
            res = max(res, ((long long)nums[i] * (r - l)));
            // res %= 1000000007;
        }
        return res % 1000000007;
    }
};