class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 1, j = 1;
        bool ans = true;
        while (i < n)
        {
            while (j < m)
            {
                if (matrix[i][j] != matrix[i - 1][j - 1])
                {

                    ans = false;
                }
                j++;
            }
            j = 1;
            i++;
        }
        return ans;
    }
};