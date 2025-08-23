class Solution
{
public:
    int minimumArea(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int maxW = INT_MIN, maxH = INT_MIN;
        int minW = INT_MAX, minH = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    maxW = max(maxW, i);
                    maxH = max(maxH, j);
                    minH = min(minH, j);
                    minW = min(minW, i);
                }
            }
        }
        // maxW++;
        // maxH++;
        return (maxW - minW + 1) * (maxH - minH + 1);
    }
};