class Solution
{
public:
    int superpalindromesInRange(string left, string right)
    {
        long long l = stol(left);
        long long r = stol(right);
        int magic = 100000;
        int ans = 0;
        for (int k = 1; k < magic; k++)
        {
            string sb = to_string(k);
            for (int i = sb.length() - 2; i >= 0; i--)
            {
                sb.push_back(sb[i]);
            }
            long long v = stol(sb);
            v *= v;
            string vs = to_string(v);
            string rv(vs.rbegin(), vs.rend());
            if (v > r)
                break;
            if (v >= l && vs == rv)
                ans++;
        }
        for (int k = 1; k < magic; k++)
        {
            string sb = to_string(k);
            for (int i = sb.length() - 1; i >= 0; i--)
            {
                sb.push_back(sb[i]);
            }
            long long v = stol(sb);
            v *= v;
            string vs = to_string(v);
            string rv(vs.rbegin(), vs.rend());
            if (v > r)
                break;
            if (v >= l && vs == rv)
                ans++;
        }
        return ans;
    }
};