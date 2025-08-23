class Solution
{
public:
    int n = 0, m = 0;
    bool solve(vector<vector<char>> &board, int i, int j, int idx,
               string &word)
    {
        if (idx == word.size())
            return true;
        if (i < 0 or j < 0 or i >= n or j >= m or board[i][j] != word[idx])
        {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '#'; // visited

        bool up = solve(board, i + 1, j, idx + 1, word);
        bool down = solve(board, i, j + 1, idx + 1, word);
        bool left = solve(board, i - 1, j, idx + 1, word);
        bool right = solve(board, i, j - 1, idx + 1, word);
        board[i][j] = temp;
        return up or down or left or right;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        n = board.size();
        m = board[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (solve(board, i, j, 0, word))
                {
                    return true;
                }
            }
        }
        return false;
    }
};