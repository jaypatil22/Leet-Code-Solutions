class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        int rowBegin = 0, rowEnd = matrix.size() - 1, colBegin = 0, colEnd = matrix[0].size() - 1;
        int dir = 0;
        while (rowBegin <= rowEnd && colBegin <= colEnd)
        {
            if (dir == 0)
            {
                for (int i = colBegin; i <= colEnd; i++)
                {
                    res.emplace_back(matrix[rowBegin][i]);
                }
                rowBegin++;
            }
            else if (dir == 1)
            {
                for (int i = rowBegin; i <= rowEnd; i++)
                {
                    res.emplace_back(matrix[i][colEnd]);
                }
                colEnd--;
            }
            else if (dir == 2)
            {
                for (int i = colEnd; i >= colBegin; i--)
                {
                    res.emplace_back(matrix[rowEnd][i]);
                }
                rowEnd--;
            }
            else
            {
                for (int i = rowEnd; i >= rowBegin; i--)
                {
                    res.emplace_back(matrix[i][colBegin]);
                }
                colBegin++;
            }
            dir++;
            dir %= 4;
        }
        return res;
    }
};