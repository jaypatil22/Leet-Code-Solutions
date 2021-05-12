class Solution
{
public:
    int getMinSwaps(string num, int k)
    {
        int res = 0;
        string a(num);
        for (int i = 0; i < k; i++)
        {
            next_permutation(a.begin(), a.end());
        }
        int n = a.size();
        for (int i = 0; i < n; i++)
        {
            if (a[i] != num[i])
            {
                int j = i + 1;
                while (num[j] != a[i])
                    j++;
                for (; j > i; j--)
                {
                    swap(num[j], num[j - 1]), res++;
                }
            }
        }
        return res;
    }
};