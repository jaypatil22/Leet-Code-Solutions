static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution
{
public:
    int firstUniqChar(string s)
    {
        vector<int> m(26);
        for (int i = s.size() - 1; i >= 0; i--)
        {
            m[s[i] - 'a']++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (m[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};