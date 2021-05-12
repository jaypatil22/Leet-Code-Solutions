class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int cur = 0, ma = INT_MIN;
        for (int i = 0; i < k; i++)
        {
            cur += cardPoints[i];
        }
        ma = cur;
        int j = k - 1;
        for (int i = 0; i < k; i++, j--)
        {
            cur -= cardPoints[j];
            cur += cardPoints[cardPoints.size() - 1 - i];
            ma = max(ma, cur);
        }
        return ma;
    }
};