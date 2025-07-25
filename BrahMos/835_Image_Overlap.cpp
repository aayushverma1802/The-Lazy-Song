class Solution
{
public:
    int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2)
    {
        int n = img1.size();
        int m = img2[0].size();
        if (n == 1 && m == 1)
        {
            return (img1[0][0] == 1 && img2[0][0] == 1) ? 1 : 0;
        }

        int maxCnt = 0;
        for (int row_off = -n + 1; row_off < n; row_off++)
        {
            for (int col_off = -n + 1; col_off < n; col_off++)
            {
                int count = 0;
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        // Find indices of B from A
                        int b_i = i + row_off;
                        int b_j = j + col_off;
                        if (b_i < 0 or b_i >= n or b_j < 0 or b_j >= n)
                        {
                            continue;
                        }
                        if (img1[i][j] == 1 and img2[b_i][b_j])
                        {
                            count++;
                        }
                    }
                }
                maxCnt = max(maxCnt, count);
            }
        }

        return maxCnt;
    }
};
