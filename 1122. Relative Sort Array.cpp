class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        map<int, int> m;
        for (int i = 0; i < arr1.size(); i++)
        {
            m[arr1[i]] = 2000 + arr1[i];
        }
        for (int i = 0; i < arr2.size(); i++)
        {
            m[arr2[i]] = i;
        }
        sort(arr1.begin(), arr1.end(), [&](const int a, const int b) { return m[a] < m[b]; });
        return arr1;
    }
};