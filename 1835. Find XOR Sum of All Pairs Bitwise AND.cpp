class Solution
{
public:
    int getXORSum(vector<int> &arr1, vector<int> &arr2)
    {
        for (int i = 1; i < arr1.size(); i++)
        {
            arr1[i] ^= arr1[i - 1];
        }
        for (int i = 1; i < arr2.size(); i++)
        {
            arr2[i] ^= arr2[i - 1];
        }
        return arr1[arr1.size() - 1] & arr2[arr2.size() - 1];
    }
};