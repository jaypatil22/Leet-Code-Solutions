class Solution
{
public:
    bool check(vector<vector<char>> &board, string &word, int i, int row, int col)
    {
        if (i == word.size())
            return true;
        if (row < 0 || row == board.size() || col < 0 || col == board[0].size())
            return false;
        if (board[row][col] != word[i])
            return false;
        char r = board[row][col];
        board[row][col] = '0';
        // cout << board[row][col] << " ";
        bool res = check(board, word, i + 1, row - 1, col) ||
                   check(board, word, i + 1, row, col - 1) ||
                   check(board, word, i + 1, row + 1, col) ||
                   check(board, word, i + 1, row, col + 1);
        board[row][col] = r;
        return res;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (check(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
};