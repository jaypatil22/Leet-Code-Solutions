class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        int stone;
        int n = box.size(), m = box[0].size();
        for (int i = 0; i < n; i++)
        {
            stone = m - 1;
            for (int j = m - 1; j >= 0; j--)
            {
                if (box[i][j] == '*')
                {
                    stone = j - 1;
                }
                else if (box[i][j] == '#')
                {
                    box[i][j] = '.';
                    box[i][stone] = '#';
                    stone--;
                }
            }
        }
        vector<vector<char>> res(m, vector<char>(n));
        for (int j = n - 1; j >= 0; j--)
        {
            for (int i = 0; i < m; i++)
            {
                res[i][n - 1 - j] = box[j][i];
            }
        }
        return res;
    }
};