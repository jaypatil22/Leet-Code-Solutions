class Solution
{
public:
    int longestValidParentheses(string s)
    {
        vector<int> stack = {-1};
        int res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                stack.emplace_back(i);
            }
            else if (stack.size() == 1)
            {
                stack[0] = i;
            }
            else
            {
                stack.pop_back();
                res = max(res, i - stack.back());
            }
        }
        return res;
    }
};